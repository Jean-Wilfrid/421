/*Locate the first occurence of a character in a string
 *@pre : str != NULL
 *@post :_
 *result : A pointer on the chracter is found, NULL else
 */
char* locate(char* str, char c)
{
    char* seeked = NULL;
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] == c)
        {
            seeked = str + i;
            break;
        }
        i++;
    }
    return seeked;
}

/*Reads an input from the standart input with at most one less than length. The final null  byte '\0' is stored at the end of the string
 *@pre :str != NULL and length is int type
 *@post : The string str is filled with a string read from the stdin with the length specified
 *@result : 1 if no error occurs 0 else
 */
int read (char* str, int length)
{
    char* position = NULL;
    if (fgets(str, length, stdin) != NULL)
    {
        position = locate (str,'\n');
        if (position != NULL)
        {
            *position = '\0';
        }
        else
        {
            cleanBuffer();
        }
        return 1;
    } 
    else
    {
        cleanBuffer();
        return 0;
    }
    cleanBuffer();
}

/*Get all the characters reamining in the buffer
 *@pre : _
 *@post : No more character in the buffer
 *@result :_
 */
void cleanBuffer()
{
    int c = 0;
    while (c != '\n' && c != '\0')
    {
        c = getchar();
    }
}