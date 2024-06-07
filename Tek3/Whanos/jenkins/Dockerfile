FROM jenkins/jenkins:latest

ENV JAVA_OPTS -Djenkins.install.runSetupWizard=false

COPY plugins.txt /var/jenkins_home/plugins.txt
RUN jenkins-plugin-cli --plugin-file /var/jenkins_home/plugins.txt

COPY whanos.yml /var/jenkins_home/casc_configs/
COPY jobs.groovy /usr/share/jenkins/ref/init.groovy.d/

COPY --chown=jenkins:jenkins . /var/jenkins_home/casc_configs/

COPY whanos.yml /var/jenkins_home/casc_configs/
COPY jobs.groovy /usr/share/jenkins/ref/init.groovy.d/

EXPOSE 8080

EXPOSE 50000