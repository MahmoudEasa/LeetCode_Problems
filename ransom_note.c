bool canConstruct(char* ransomNote, char* magazine) {
    short i = 0, j, found;
    

    while (ransomNote[i])
    {
        found = 0;
        j = 0;
        while (magazine[j])
        {
            if (ransomNote[i] == magazine[j])
            {
                found = 1;
                magazine[j] = '\n';
                break;
            }
            j++;
        }

        if (!found) return (0);
        i++;
    }

    return (1);
}
