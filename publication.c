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
    pub->pages = 0;
    pub->cout_quotes = 0;
    return pub;
}