pipeline {
    environment {
        GIT_USER_EMAIL = sh (
            script: 'git --no-pager show -s --format="%ae"',
            returnStdout: true
        )
        GIT_USER_NAME = sh (
            script: 'git --no-pager show -s --format="%an"',
            returnStdout: true
        )
        GIT_COMMIT_DETAIL = sh (
            script: 'git --no-pager show -s',
            returnStdout: true
        )
    }
    agent { docker { image 'node:16.13.1-alpine' } }
    stages {
        stage('builddddss') {
            steps {
                sh 'node --version'
            }
        }
    }
}