pipeline {
    agent any
    stages {
        stage('Build') {
            steps {
                checkout scm
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
