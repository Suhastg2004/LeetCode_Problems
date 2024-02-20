bool isValid(char* s) {
    char st[100];
    int top = -1;
    for(int i = 0; s[i] != '\0'; i++) {  
        if(s[i] == '(' || s[i] == '{' || s[i] == '[') {
            st[++top] = s[i];
        }
        else if(s[i] == ')' || s[i] == '}' || s[i] == ']') {
            if(top == -1)
                return false;
            else if(s[i] == ')' && st[top] != '(')
                return false;
            else if(s[i] == '}' && st[top] != '{')
                return false;
            else if(s[i] == ']' && st[top] != '[')
                return false;
            top--; // After successfully matching, decrement top
        }
    }
    if(top == -1)
        return true;
    else
        return false;   
}
