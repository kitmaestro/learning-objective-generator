#include <stdio.h>
#include "../config.h"

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

void
export_objective(char *objective)
{
}