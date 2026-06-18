#include <stdio.h>
#include <string.h>

#define MAX_LINE 222

void printClean(FILE *out, char *line)
{
    char *ptr = strchr(line, ':');
    if(ptr)
    {
        ptr++; // I'm skipping the colon
        while(*ptr == '\"' || *ptr == ' ')
        {
            ptr++;
        }
        while(*ptr != '\"')
        {
            fputc(*ptr, out);
            ptr++;
        }
        fputc('\n', out);
    }
}



int main()
{
    FILE *playersRaw = fopen("json.txt", "r");
    FILE *out = fopen("players.txt", "w");
    char line[MAX_LINE];
    if(playersRaw == NULL)
    {
        printf("Error while opening\n");
        return 1;
    }
    while (fgets(line, sizeof(line), playersRaw))
    {   
        if(strstr(line, "\"forename\"") || strstr(line, "\"roleType\"") || strstr(line, "\"teamName\"") || strstr(line, "\"surname\""))
        {
            printClean(out, line);
        }
        
        if(strstr(line, "\"price\""))
        {
            printClean(out, line);
            fputc('\n', out);
        }
    }

    fclose(out);
    fclose(playersRaw);

}
