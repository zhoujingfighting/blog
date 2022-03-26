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
    agent any
    stages {
        stage('Build') {
            steps {
                echo 'Building'
            }
        }
        stage('Test') {
            steps {
                echo 'Testing'
            }
        }
        stage('Deploy') {
            steps {
                echo 'Deploying'
            }
        }
    }
}