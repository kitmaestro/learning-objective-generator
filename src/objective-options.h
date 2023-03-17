#ifndef _OBJECTIVE_OPTIONS_H_
#define _OBJECTIVE_OPTIONS_H_

typedef struct objective_options
{
    int level;
    int grade;
    int domain_level;
    char subject;
    char* topic;
} ObjectiveOptions;

extern ObjectiveOptions * objective_options_new(void);

extern ObjectiveOptions * objective_options_new_from_values(int level, int grade, int domain_level, char subject, char* topic);

extern void objective_options_set_level(ObjectiveOptions* opt, int level);

extern int objective_options_get_level(ObjectiveOptions* opt);

extern void objective_options_set_grade(ObjectiveOptions* opt, int grade);

extern int objective_options_get_grade(ObjectiveOptions *opt);

extern void objective_options_set_domain_level(ObjectiveOptions* opt, int level);

extern int objective_options_get_domain_level(ObjectiveOptions *opt);

extern void objective_options_set_subject(ObjectiveOptions* opt, char subject);

extern char objective_options_get_subject(ObjectiveOptions *opt);

extern void objective_options_set_topic(ObjectiveOptions* opt, char* topic);

extern char* objective_options_get_topic(ObjectiveOptions* opt);

extern void objective_options_destroy(ObjectiveOptions *opt);

#endif