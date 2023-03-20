#include "RPN.hpp"


int ft_strlen(const char *str)
{
    int  i = 0;
    while (str[i])
        i++;
    return (i);
}

int deux_operateurs(char *str)
{
    int j = ft_strlen(str);
    if (isdigit(str[j-3]))
        return (0);
    return (1);
}

std :: stack<char> first_function(const char *str)
{
    std :: stack<char> calcul;
    int i = ft_strlen(str)-1;
    while (str[i])
    {
        if (str[i] != ' ')
            calcul.push(str[i]);
        i--;
    }
    return (calcul);
}

int polonaise(const char *str)
{
    std :: stack <char> ms = first_function(str);
    int sum1 = 0;
    int i = 0;
    int j = 0;

    i = ms.top()-'0';
    ms.pop();
    j = ms.top()-'0';
    ms.pop();
    sum1 = le_calcul(i, j, ms.top());
    ms.pop();
	while (!ms.empty())
	{
		i = ms.top()-'0';
        ms.pop();
        sum1 = le_calcul(sum1, i, ms.top());
        ms.pop();
	}
    return (sum1);
}

int parsing(char *str)
{
    int i = 0;
    while(str[i])
    {
        if (!(isdigit(str[i]) || str[i] == '-' || str[i] =='+' 
        || str[i] == '/' || str[i] == '*' || str[i] == ' '))
            return(0);
        i++;
    }
    return (1);
}

int le_calcul(int a, int b, char c)
{
    if (c == '+')
        return (a+b);
    else if (c == '-')
        return (a-b);
    else if (c == '*')
        return (a*b);
    else if (c == '/')
        return(a/b);
    return (0);
}