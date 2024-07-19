#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_JOBS 100
#define MAX_APPLICANTS 100
#define MAX_INTERVIEWS 100
#define MAX_EVALUATIONS 100
#define MAX_NAME_LENGTH 100

typedef struct {
    int id;
    char title[MAX_NAME_LENGTH];
    char description[MAX_NAME_LENGTH];
} JobPosting;

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    char email[MAX_NAME_LENGTH];
    int jobId;
} Applicant;

typedef struct {
    int id;
    int applicantId;
    char date[MAX_NAME_LENGTH];
    char time[MAX_NAME_LENGTH];
} Interview;

typedef struct {
    int id;
    int applicantId;
    char feedback[MAX_NAME_LENGTH];
    int score;
} Evaluation;

void addJobPosting(JobPosting jobPostings[], int *jobCount) {
    if (*jobCount >= MAX_JOBS) {
        printf("Cannot add more job postings. Maximum limit reached.\n");
        return;
    }
    JobPosting newJob;
    newJob.id = *jobCount + 1;
    printf("Enter job title: ");
    scanf(" %[^\n]%*c", newJob.title);
    printf("Enter job description: ");
    scanf(" %[^\n]%*c", newJob.description);
    jobPostings[*jobCount] = newJob;
    (*jobCount)++;
    printf("Job added successfully!\n");
}

void listJobPostings(JobPosting jobPostings[], int jobCount) {
    for (int i = 0; i < jobCount; i++) {
        printf("ID: %d, Title: %s, Description: %s\n", jobPostings[i].id, jobPostings[i].title, jobPostings[i].description);
    }
}

void addApplicant(Applicant applicants[], int *applicantCount, int jobCount) {
    if (*applicantCount >= MAX_APPLICANTS) {
        printf("Cannot add more applicants. Maximum limit reached.\n");
        return;
    }
    Applicant newApplicant;
    newApplicant.id = *applicantCount + 1;
    printf("Enter applicant name: ");
    scanf(" %[^\n]%*c", newApplicant.name);
    printf("Enter applicant email: ");
    scanf(" %[^\n]%*c", newApplicant.email);
    printf("Enter job ID for application: ");
    scanf("%d", &newApplicant.jobId);
    if (newApplicant.jobId > 0 && newApplicant.jobId <= jobCount) {
        applicants[*applicantCount] = newApplicant;
        (*applicantCount)++;
        printf("Applicant added successfully!\n");
    } else {
        printf("Invalid job ID!\n");
    }
}

void listApplicants(Applicant applicants[], int applicantCount) {
    for (int i = 0; i < applicantCount; i++) {
        printf("ID: %d, Name: %s, Email: %s, Job ID: %d\n", applicants[i].id, applicants[i].name, applicants[i].email, applicants[i].jobId);
    }
}

void scheduleInterview(Interview interviews[], int *interviewCount, int applicantCount) {
    if (*interviewCount >= MAX_INTERVIEWS) {
        printf("Cannot schedule more interviews. Maximum limit reached.\n");
        return;
    }
    Interview newInterview;
    newInterview.id = *interviewCount + 1;
    printf("Enter applicant ID: ");
    scanf("%d", &newInterview.applicantId);
    if (newInterview.applicantId > 0 && newInterview.applicantId <= applicantCount) {
        printf("Enter interview date (YYYY-MM-DD): ");
        scanf(" %[^\n]%*c", newInterview.date);
        printf("Enter interview time (HH:MM): ");
        scanf(" %[^\n]%*c", newInterview.time);
        interviews[*interviewCount] = newInterview;
        (*interviewCount)++;
        printf("Interview scheduled successfully!\n");
    } else {
        printf("Invalid applicant ID!\n");
    }
}

void listInterviews(Interview interviews[], int interviewCount) {
    for (int i = 0; i < interviewCount; i++) {
        printf("ID: %d, Applicant ID: %d, Date: %s, Time: %s\n", interviews[i].id, interviews[i].applicantId, interviews[i].date, interviews[i].time);
    }
}

void addEvaluation(Evaluation evaluations[], int *evaluationCount, int applicantCount) {
    if (*evaluationCount >= MAX_EVALUATIONS) {
        printf("Cannot add more evaluations. Maximum limit reached.\n");
        return;
    }
    Evaluation newEvaluation;
    newEvaluation.id = *evaluationCount + 1;
    printf("Enter applicant ID: ");
    scanf("%d", &newEvaluation.applicantId);
    if (newEvaluation.applicantId > 0 && newEvaluation.applicantId <= applicantCount) {
        printf("Enter feedback: ");
        scanf(" %[^\n]%*c", newEvaluation.feedback);
        printf("Enter score (0-100): ");
        scanf("%d", &newEvaluation.score);
        evaluations[*evaluationCount] = newEvaluation;
        (*evaluationCount)++;
        printf("Evaluation added successfully!\n");
    } else {
        printf("Invalid applicant ID!\n");
    }
}

void listEvaluations(Evaluation evaluations[], int evaluationCount) {
    for (int i = 0; i < evaluationCount; i++) {
        printf("ID: %d, Applicant ID: %d, Feedback: %s, Score: %d\n", evaluations[i].id, evaluations[i].applicantId, evaluations[i].feedback, evaluations[i].score);
    }
}

int main() {
    JobPosting jobPostings[MAX_JOBS];
    int jobCount = 0;

    Applicant applicants[MAX_APPLICANTS];
    int applicantCount = 0;

    Interview interviews[MAX_INTERVIEWS];
    int interviewCount = 0;

    Evaluation evaluations[MAX_EVALUATIONS];
    int evaluationCount = 0;

    int choice;

    do {
        printf("\nHR Management System\n");
        printf("1. Add Job Posting\n");
        printf("2. List Job Postings\n");
        printf("3. Add Applicant\n");
        printf("4. List Applicants\n");
        printf("5. Schedule Interview\n");
        printf("6. List Interviews\n");
        printf("7. Add Evaluation\n");
        printf("8. List Evaluations\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addJobPosting(jobPostings, &jobCount);
                break;
            case 2:
                listJobPostings(jobPostings, jobCount);
                break;
            case 3:
                addApplicant(applicants, &applicantCount, jobCount);
                break;
            case 4:
                listApplicants(applicants, applicantCount);
                break;
            case 5:
                scheduleInterview(interviews, &interviewCount, applicantCount);
                break;
            case 6:
                listInterviews(interviews, interviewCount);
                break;
            case 7:
                addEvaluation(evaluations, &evaluationCount, applicantCount);
                break;
            case 8:
                listEvaluations(evaluations, evaluationCount);
                break;
            case 9:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 9);

    return 0;
}
