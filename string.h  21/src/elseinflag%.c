else if (*format == '%') {
  str = print_c(str, specs, '%');
}
else {
  str = S21_NULL;
}