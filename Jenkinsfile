pipeline {
    agent any
    checkout scm
    stages {
        stage('Build') {
            steps {
                sh 'gbp buildpackage'
            }
        }
        // stage('Test') {
        //     steps {
        //         echo 'Testing..'
        //     }
        // }
        // stage('Deploy') {
        //     steps {
        //         echo 'Deploying....'
        //     }
        // }
    }
}
