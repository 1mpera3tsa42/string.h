// обработка p флага

char *print_p(char *str, Spec specs, va_list *arguments) {
  // получаем из агрументов адрес
  unsigned long int ptr =
      (unsigned long int)va_arg(*arguments, unsigned long int);
  //  устанавливаем параметры для 16-ой системы, чтобы строка имела вид
  //  8-х.......
  specs->number_system = 16;
  specs->hash = 1;
  specs->upper_case = 0;

  s21_size_t size_to_num = get_buf_size_unsigned_decimal(*specs, ptr);
  char *buffer = calloc(sizeof(char) * size_to_num);
  if (buffer) {
    int i = unsigned_decimal_to_string(buffer, *specs, ptr, size_to_num);
    str += add_buffer_to_string(specs->wedth, &i, buffer, str);
  }
  if (buffer) free(buffer);
  return str;
}
