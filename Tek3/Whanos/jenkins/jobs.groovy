import hudson.plugins.docker.commons.credentials.*

// Configure Jenkins to use Docker
def configureDocker() {
    docker.withServer('docker-host') {
        docker.withRegistry('https://registry.example.com', 'docker-credentials-id') {
            // This block is necessary to configure Docker inside Jenkins
            // You may need to adjust the server URL and credentials ID accordingly
        }
    }
}

configureDocker()

// USERS
def usersConfig = configure {
    security {
        authorizationStrategy(allowAnonymousRead())
        disableSignup()
        addUser {
            username('Admin')
            id('admin')
            permissions('FULL_CONTROL')
        }
    }
}

// FOLDERS
def foldersConfig = configure {
    folders {
        // WHANOS BASE IMAGES
        folder {
            name('Whanos base images')
            displayName('Whanos base images')
            description('Folder for Whanos base images')
            properties {
                folderProperties()
            }
        }
        // PROJECTS
        folder {
            name('Projects')
            displayName('Projects')
            description('Folder for projects')
            properties {
                folderProperties()
            }
        }
    }
}

// JOBS

def supportedLanguages = ["befunge", "c", "java", "javascript", "python"]

// WHANOS BASE IMAGES BUILD JOBS
supportedLanguages.each { language ->
    freeStyleJob("whanos-${language}") {
        displayName("whanos-${language}")
        description("Build whanos-${language} base image")
        folder('Whanos base images')
        steps {
            shell("docker build -t images/whanos-${language} -f  images/${language}/Dockerfile.base whanos-${language}")
        }
    }
}

// BUILD ALL BASE IMAGES
freestyleJob('Build all base images') {
    displayName('Build all base images')
    description('Build all base images is located in the Whanos base images folder and when executed, triggers all base images build jobs')
    folder('Whanos base images')
    steps {
        supportedLanguages.each { language ->
            build("whanos-${language}")
        }
    }
}

// JOBS CREATED BY THE link-project JOB
freestyleJob('link-project') {
    displayName('link-project')
    description('link-project is at root and when executed, links the specified project in the parameters to the Whanos infrastructure by creating a job with the specifications listed below')
    folder('Projects')
    parameters {
        stringParam('projectName', '', 'Project name')
        stringParam('gitUrl', '', 'Git url')
        stringParam('gitBranch', '', 'Git branch')
        stringParam('dockerfile', '', 'Dockerfile')
        stringParam('dockerImageName', '', 'Docker image name')
        stringParam('dockerImageTag', '', 'Docker image tag')
        stringParam('kubernetesNamespace', '', 'Kubernetes namespace')
        stringParam('kubernetesDeploymentName', '', 'Kubernetes deployment name')
        stringParam('kubernetesServiceName', '', 'Kubernetes service name')
        stringParam('kubernetesServicePort', '', 'Kubernetes service port')
    }
    steps {
        script {
            // Project specifications
            def projectName = params.projectName
            def gitUrl = params.gitUrl
            def gitBranch = params.gitBranch

            // Whanos images specifications
            def dockerfile = params.dockerfile
            def dockerImageName = params.dockerImageName
            def dockerImageTag = params.dockerImageTag

            // Kubernetes specifications
            def kubernetesNamespace = params.kubernetesNamespace
            def kubernetesDeploymentName = params.kubernetesDeploymentName
            def kubernetesServiceName = params.kubernetesServiceName
            def kubernetesServicePort = params.kubernetesServicePort

            // Job specifications
            def jobName = "whanos-${projectName}"
            def jobFolder = "Projects"
            def jobDisplayName = "whanos-${projectName}"
            def jobDescription = "whanos-${projectName} is located in the Projects folder and when executed, checks every minute for changes in the repository and if a change is detected, containerizes the respository’s application according to the specifications described in the Whanos images specifications section and if applicable, deploys the application into a Kubernetes cluster (see below)."


            def job = freeStyleJob(jobName) {
                displayName(jobDisplayName)
                description(jobDescription)
                folder("Projects")
                scm {
                    git {
                        remote {
                            url(gitUrl)
                            credentials('git-credentials-id')
                        }
                        branch(gitBranch)
                    }
                }
                triggers {
                    scm('* * * * *')
                }
                steps {
                    // Copy Dockerfile to the job directory
                    copy {
                        // projectName is the name of the job
                        from('images/' + projectName + '/' + dockerfile)
                        into('.')
                    }

                    // Build Docker image
                    script {
                        if (!dockerImageName || !dockerImageTag || !dockerfile) {
                            // Use Dockerfile.standalone when parameters are missing
                            dockerfile = "images/${language}/Dockerfile.standalone"
                            echo "Parameters missing, using Dockerfile.standalone"
                        }

                        sh("docker build -t ${dockerImageName}:${dockerImageTag} -f ${dockerfile} .")
                    }


                    // Deploy to Kubernetes
                    script {
                        if (kubernetesNamespace) {
                            sh("kubectl apply -f ${kubernetesDeploymentName} -n ${kubernetesNamespace}")
                            sh("kubectl apply -f ${kubernetesServiceName} -n ${kubernetesNamespace}")
                        }
                    }
                }
            }
        }
    }
}
