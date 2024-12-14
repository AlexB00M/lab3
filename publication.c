#include "publication.h"

/*
Название публикации: строка
Фамилия первого автора: строка
Инициалы первого автора: строка
Название журнала: строка
Год публикации: четырехзначное число
Том журнала: целое число
Входит в РИНЦ: логическое значение
Количество страниц: целое число
Цитирований: целое число
*/
//char *name_publication, char *surname, char *iinitials, char *name_journal, int date, int tom, bool in_RINC, int pages, int cout_quotes

publication *creat_publication(){
    publication *pub = (publication *)malloc(sizeof(publication));
    pub->name_publication = NULL;
    pub->surname = NULL;
    pub->iinitials = NULL;
    pub->name_journal = NULL;
    pub->date = 0;
    pub->tom = 0;
    pub->in_RINC = false;
    pub->pages = 0;
    pub->cout_quotes = 0;

    return pub;
}

char *yes_no(bool a){
    if (a == true){
        char *res = (char *)malloc(4);
        res = "YES";
        return res;
    } else {
        char *res = (char *)malloc(3);
        res = "NO";
        return res;
    }
}