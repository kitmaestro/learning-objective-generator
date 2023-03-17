#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "objective-options.h"

#define PROJECT_NAME "LearningObjectiveGenerator"
#define PROJECT_VERSION "1.0"

void
print_help
(void)
{
    printf("Learning Objective Generator v%s\n", PROJECT_VERSION);
    printf("\nUsage: learningobjectivegenerator -l (1-4) -g (1-6) -s (s|e|f|m|h|c|a|r|p) -d (1-6) TOPIC [-o out.txt]\n");
    printf("\t-l. \tLevel: 1=kinder 2=primary, 3=secondary, 4=special education\n");
    printf("\t-g.\t\tGrade: The target grade. 1 to 6\n");
    printf("\t-s. \tSubject: s=spanish, e=english, f=french, m=math, h=history, c=science, a=art, r=religion, p=phisical education\n");
    printf("\t-d. \tDomain Level: bloom's taxonomy level. 1=Remembering 2=Understanding 3=Applying 4=Analyzing 5=Evaluating 6=Creating\n");
    printf("\t-o. \tOutput. Result's output file, defaults to out.txt\n");
    printf("\tTOPIC. \t\tThe topic you want to generate an objective for\n");
}

char *output_file_name;

int
main
(int argc, char **argv)
{
    if (argc < 6)
    {
        printf("%s takes at least 5 arguments.\n", argv[0]);
        print_help();
        return 1;
    }
    int previous_was_option = 0;
    ObjectiveOptions* options;
    options = objective_options_new();
    int i = 0;

    for (i = 1; i < argc; i++) 
    {
        if (argv[i][0] == '-')
        {
            previous_was_option = 1;
            if (argv[i][1] == 'l') 
            {
                // level
                if (argc > i + 1)
                {
                    int level = atoi(argv[i + 1]);
                    if (level < 7 && level > 0) {
                        objective_options_set_level(options, level);
                    }
                    continue;
                }
                else
                {
                    // user didn't provided more info
                }
            }
            if (argv[i][1] == 'g') {
                // grade
                if (argc > i + 1)
                {
                    int grade = atoi(argv[i + 1]);
                    if (grade < 7 && grade > 0)
                    {
                        objective_options_set_grade(options, grade);
                    }
                    continue;
                }
                else
                {
                    // user didn't provided more info
                }
            }
            if (argv[i][1] == 's') {
                // subject
                if (argc > i + 1)
                {
                    char subject = argv[i + 1][0];
                    objective_options_set_subject(options, subject);
                    continue;
                }
                else
                {
                    // user didn't provided more info
                }
            }
            if (argv[i][1] == 'd') {
                // domain level
                if (argc > i + 1)
                {
                    int domain_level = atoi(argv[i + 1]);
                    if (domain_level < 7 && domain_level > 0)
                    {
                        objective_options_set_domain_level(options, domain_level);
                    }
                    continue;
                }
                else
                {
                    // user didn't provided more info
                }
            }
            if (argv[i][1] == 'o') {
                // output file
                if (argc > i + 1)
                {
                    output_file_name = (char *) malloc(100);
                    strcpy(output_file_name, argv[i + 1]);
                }
                else
                {
                    // user didn't provided more info
                    // let's use the default: out.txt
                    output_file_name = (char *) malloc(100);
                    strcpy(output_file_name, "out.txt");
                }
            }
        } else {
            if (previous_was_option == 1) {
                // this is the match for an option
                previous_was_option = 0;
                continue;
            } else {
                // let's say this is the topic
                objective_options_set_topic(options, argv[i]);
                // end the loop
                break;
            }
        }
    }

    printf("Parsed options:\n");
    printf("Level: %d\n", objective_options_get_level(options));
    printf("Grade: %d\n", objective_options_get_grade(options));
    printf("Domain_level: %d\n", objective_options_get_domain_level(options));
    printf("Subject: %c\n", objective_options_get_subject(options));
    printf("Topic: %s\n", objective_options_get_topic(options));

    return 0;
}
