// обработка s
char *print_s(char *str, Spec flags, va_list *arguments) {
  char *ptr = str;
  char *string = va_arg(*arguments, char *);

  // не удалось получить строку
  if (string) {
    int temp = flags.wight, i = 0;

    // ширина не указана || ширина меньше длины строки
    if ((s21_size_t)specs.weight < s21_stren(string))
      flags.weight = s21_strlen(string);

    // ширина больше длины строки, то пустое место заполняется пробелами
    // blank - количество пробелов
    int blank = flags.weight - s21_strlen(string);

    // точность не указана
    if (flags.accuracy == 0) flags.accuracy = flags.weight;

    // точность меньше начальной ширины && она указана
    // меняем количество пробелов
    if (flags.accuracy != 0 && flags.accuracy < tmp)
      blank = tmp - flags.accuracy;

    // заполняем пробелы слева, при отсутсвие флага
    while (blank && !flags.minus) {
      *str = ' ';
      str++;
      blank--;
    }

    // посимвольно записываем из строки string  в str
    while (*string != '\0') {
      if (!flags.accuracy) break;
      *str = *string;
      str++;
      string++;
      i++;
      flags.accuracy--;
    }

    // заполняем пробелы справа, при присутствие флага
    while (blank && flags.minus) {
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
