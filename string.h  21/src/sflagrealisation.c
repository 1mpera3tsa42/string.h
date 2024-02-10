// обработка s
char *print_s(char *str, Spec specs, va_list *arguments) {
  char *ptr = str;
  char *string = va_arg(*arguments, char *);

  // не удалось получить строку
  if (string) {
    int temp = specs.wight, i = 0;

    // ширина не указаан || ширина меньше длины строки
    if ((s21_size_t)specs.weight < s21_stren(string))
      specs.weight = s21_strlen(string);

    // ширина больше длины строки, то пустое место заполняется пробелами
    // blank - количество пробелов
    int blank = specs.weight - s21_strlen(string);

    // точность не указана
    if (specs.accuracy == 0) specs.accuracy = specs.weight;

    // точность меньше начальной ширины && она указана
    // меняем количество пробелов
    if (specs.accuracy != 0 && specs.accuracy < tmp)
      blank = tmp - specs.accuracy;

    // заполняем пробелы слева, при отсутсвие флага
    while (blank && !specs.minus) {
      *str = ' ';
      str++;
      blank--;
    }

    // посимвольно записываем из строки string  в str
    while (*string != '\0') {
      if (!specs.accuracy) break;
      *str = *string;
      str++;
      string++;
      i++;
      specs.accuracy--;
    }

    // заполняем пробелы справа, при присутствие флага
    while (blank && specs.minus) {
      *str = ' ';
      str++;
      blank--;
    }
  } else {
    // не удалось получить строку из параметра, записываем в строку NULL
    str = s21_memcpy(str, "(null)", 6);
    str += 6;
  }

  // присваиваем ptr str и возвращаем его, чтобы передвинуть указатель нашей
  // строки
  if (ptr) ptr = str;
  return ptr;
}
