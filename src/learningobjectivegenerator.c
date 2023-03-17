#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "config.h"

#include "lib/utils.h"
#include "lib/objective-options.h"

#include "generators/spanish-generator.h"
#include "generators/art-generator.h"
#include "generators/french-generator.h"
#include "generators/history-generator.h"
#include "generators/math-generator.h"
#include "generators/physical-education-generator.h"
#include "generators/religion-generator.h"
#include "generators/science-generator.h"

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
    char * objective;
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
                    exit(1);
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
                    exit(1);
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
                    exit(1);
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
                    exit(1);
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
            if (previous_was_option == 1) 
            {
                // this is the match for an option
                previous_was_option = 0;
                continue;
            }
            else
            {
                // let's say this is the topic
                objective_options_set_topic(options, argv[i]);
                // end the loop
                break;
            }
        }
    }

    // Must check if I was provided with all the info I need.
    // if not, exit(1)
    if (objective_options_get_domain_level(options) < 1 ||
        objective_options_get_grade(options) < 1  ||
        objective_options_get_level(options) < 1 ||
        objective_options_get_subject(options) == '?' ||
        strlen(objective_options_get_topic(options)) < 3)
    {
        exit(1);
    }
    
    switch (objective_options_get_subject(options))
    {
        case 's':
        {
            objective = generate_spanish_objective(objective_options_get_level(options),
                                                   objective_options_get_grade(options),
                                                   objective_options_get_domain_level(options),
                                                   objective_options_get_topic(options));
            break;
        }
        case 'e':
        {
            objective = generate_english_objective(objective_options_get_level(options),
                                                   objective_options_get_grade(options),
                                                   objective_options_get_domain_level(options),
                                                   objective_options_get_topic(options));
            break;
        }
        case 'f':
        {
            objective = generate_french_objective(objective_options_get_level(options),
                                                   objective_options_get_grade(options),
                                                   objective_options_get_domain_level(options),
                                                   objective_options_get_topic(options));
            break;
        }
        case 'm':
        {
            objective = generate_math_objective(objective_options_get_level(options),
                                                   objective_options_get_grade(options),
                                                   objective_options_get_domain_level(options),
                                                   objective_options_get_topic(options));
            break;
        }
        case 'h':
        {
            objective = generate_history_objective(objective_options_get_level(options),
                                                   objective_options_get_grade(options),
                                                   objective_options_get_domain_level(options),
                                                   objective_options_get_topic(options));
            break;
        }
        case 'c':
        {
            objective = generate_science_objective(objective_options_get_level(options),
                                                   objective_options_get_grade(options),
                                                   objective_options_get_domain_level(options),
                                                   objective_options_get_topic(options));
            break;
        }
        case 'a':
        {
            objective = generate_art_objective(objective_options_get_level(options),
                                               objective_options_get_grade(options),
                                               objective_options_get_domain_level(options),
                                               objective_options_get_topic(options));
            break;
        }
        case 'p':
        {
            objective = generate_physical_education_objective(objective_options_get_level(options),
                                                   objective_options_get_grade(options),
                                                   objective_options_get_domain_level(options),
                                                   objective_options_get_topic(options));
            break;
        }
        case 'r':
        {
            objective = generate_religion_objective(objective_options_get_level(options),
                                                   objective_options_get_grade(options),
                                                   objective_options_get_domain_level(options),
                                                   objective_options_get_topic(options));
            break;
        }
        default:
        {
            // the entered subject doesn't exists
            exit(1);
        }
    }

    return 0;
}
