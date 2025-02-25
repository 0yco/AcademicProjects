folder('Tools') {
    description('Folder for miscellaneous tools.')
}

job('Tools/clone-repository') {
    description('Clone with Git the repository at the specified URL.')
    parameters {
        stringParam('GIT_REPOSITORY_URL', '', 'Git URL of the repository to clone')
    }
    steps {
        cleanWs()
        shell('git clone $GIT_REPOSITORY_URL')
    }
    triggers {
        manual('')
    }
}

job('Tools/SEED') {
    parameters {
        stringParam('GITHUB_NAME', '', 'GitHub repository owner/repo_name (e.g.: "EpitechIT31000/chocolatine")')
        stringParam('DISPLAY_NAME', '', 'Display name for the job')
    }
    steps {
        dsl {
            text('''
                job('${DISPLAY_NAME}') {
                    scm {
                        github('${GITHUB_NAME}')
                    }
                    steps {
                        cleanWs()
                        shell('make fclean')
                        shell('make')
                        shell('make tests_run')
                        shell('make clean')
                    }
                }
            ''')
        }
    }
    triggers {
        manual('')
    }
}