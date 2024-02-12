// обработка p флага

char *print_p(char *str, Spec flags, va_list *arguments) {
  // получаем из агрументов адрес
  unsigned long int ptr =
      (unsigned long int)va_arg(*arguments, unsigned long int);
  //  устанавливаем параметры для 16-ой системы, чтобы строка имела вид
  //  8-х.......
  flags->number_system = 16;
  flags->hash = 1;
  flags->upper_case = 0;

  s21_size_t size_to_num = get_buf_size_unsigned_decimal(*flags, ptr);
  char *buffer = calloc(sizeof(char) * size_to_num);
  if (buffer) {
    int i = unsigned_decimal_to_string(buffer, *flags, ptr, size_to_num);
    str += add_buffer_to_string(flags->wedth, &i, buffer, str);
  }
  if (buffer) free(buffer);
  return str;
}
