#include "libft.h"

char    *strnstr(const char *haystack, const char *needle, size_t len)
{
        size_t  j;
        size_t  i;

        i = 0;
        if (needle[0] == '\0')
        {
                return ((char *)haystack);
        }
        while (haystack[i] != '\0' &&  i < len)
        {
                j = 0;
                while (haystack[i + j] == needle[j] && needle[j] != '\0' && (j + i) < len)
                        j++;
                if (needle[j] == '\0')
                        return ((char *)(haystack + i));
                i++;
        }
        return (0);
}
#include <stdio.h>
#include <string.h>  // para comparar con la strnstr original (opcional)

// Prototipo de tu función
char *ft_strnstr(const char *haystack, const char *needle, size_t len);

int main(void)
{
    const char *text1 = "hola mundo42";
    const char *find1 = "mundo";
    const char *find2 = "mundo telef";
    const char *find3 = "hola";
    const char *find4 = "";

    char *res;

    printf("=== PRUEBAS DE ft_strnstr ===\n\n");

    // Caso 1: coincidencia normal
    res = ft_strnstr(text1, find1, 12);
    printf("Caso 1: \"%s\" en \"%s\" → %s\n",
           find1, text1, res ? res : "(null)");

    // Caso 2: needle más largo que el haystack
    res = ft_strnstr(text1, find2, 12);
    printf("Caso 2: \"%s\" en \"%s\" → %s\n",
           find2, text1, res ? res : "(null)");

    // Caso 3: coincidencia al principio
    res = ft_strnstr(text1, find3, 4);
    printf("Caso 3: \"%s\" en \"%s\" (len=4) → %s\n",
           find3, text1, res ? res : "(null)");

    // Caso 4: needle vacío (debe devolver haystack)

	// Caso 5: límite muy pequeño (no encuentra)
    res = ft_strnstr(text1, find1, 8);
    printf("Caso 5: \"%s\" en \"%s\" (len=8) → %s\n",
           find1, text1, res ? res : "(null)");

    return 0;
}
