#include <stdlib.h>
#include "objective-options.h"
#include <string.h>

ObjectiveOptions *
objective_options_new
(void)
{
    ObjectiveOptions * options = (ObjectiveOptions *) malloc(sizeof(ObjectiveOptions*));
    options->topic = (char *)malloc(256);

    options->level = 0;
    options->grade = 0;
    options->domain_level = 0;
    options->subject = '?';

    return options;
}

ObjectiveOptions *
objective_options_new_from_values
(int level, int grade, int domain_level, char subject, char *topic)
{
    ObjectiveOptions * options = (ObjectiveOptions *) malloc(sizeof(ObjectiveOptions*));

    char *valid_subjects;
    valid_subjects = (char *) malloc(9);
    valid_subjects[0] = 's';
    valid_subjects[1] = 'e';
    valid_subjects[2] = 'f';
    valid_subjects[3] = 'm';
    valid_subjects[4] = 'h';
    valid_subjects[5] = 'c';
    valid_subjects[6] = 'a';
    valid_subjects[7] = 'r';
    valid_subjects[8] = 'p';

    options->level = level;
    options->grade = grade;
    options->domain_level = domain_level;
    options->topic = (char *) malloc(256);
    strcpy(options->topic, topic);

    for (int i = 0; i < 9; i++) {
        if (subject == valid_subjects[i]) {
            options->subject = subject;
            break;
        }
    }

    return options;
}

int
objective_options_get_level
(ObjectiveOptions* opt)
{
    return opt->level;
}

void
objective_options_set_level
(ObjectiveOptions *opt, int level)
{
    opt->level = level;
}

int
objective_options_get_grade
(ObjectiveOptions *opt)
{
    return opt->grade;
}

void
objective_options_set_grade
(ObjectiveOptions *opt, int grade)
{
    opt->grade = grade;
}

int
objective_options_get_domain_level
(ObjectiveOptions *opt)
{
    return opt->domain_level;
}

void
objective_options_set_domain_level
(ObjectiveOptions *opt, int level)
{
    opt->domain_level = level;
}

char
objective_options_get_subject
(ObjectiveOptions *opt)
{
    return opt->subject;
}

void
objective_options_set_subject
(ObjectiveOptions *opt, char subject)
{
    char *valid_subjects;
    valid_subjects = (char *)malloc(9);
    valid_subjects[0] = 's';
    valid_subjects[1] = 'e';
    valid_subjects[2] = 'f';
    valid_subjects[3] = 'm';
    valid_subjects[4] = 'h';
    valid_subjects[5] = 'c';
    valid_subjects[6] = 'a';
    valid_subjects[7] = 'r';
    valid_subjects[8] = 'p';

    for (int i = 0; i < 9; i++)
    {
        if (subject == valid_subjects[i])
        {
            opt->subject = subject;
            break;
        }
    }
}

char *
objective_options_get_topic
(ObjectiveOptions* opt)
{
   return opt->topic;
}

void
objective_options_set_topic
(ObjectiveOptions *opt, char *topic)
{
    strcpy(opt->topic, topic);
}

void
objective_options_destroy
(ObjectiveOptions *opt)
{
    free(opt);
}
