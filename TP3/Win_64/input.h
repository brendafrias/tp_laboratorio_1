/**
 * \brief Solicita un número al usuario y lo valida
 * \param input Se carga el numero ingresado
 * \param message Es el mensaje a ser mostrado
 * \param eMessage Es el mensaje a ser mostrado en caso de error
 * \param lowLimit Limite inferior a validar
 * \param hiLimit Limite superior a validar
 * \return void
 */
void input_getInt(int* input, char message[], char eMessage[], int lowLimit, int hiLimit);

/**
 * \brief Solicita un número al usuario y lo valida
 * \param input Se carga el numero ingresado
 * \param message Es el mensaje a ser mostrado
 * \param eMessage Es el mensaje a ser mostrado en caso de error
 * \param lowLimit Limite inferior a validar
 * \param hiLimit Limite superior a validar
 * \return void
 */
void input_getFloat(float* input, char message[], char eMessage[], float lowLimit, float hiLimit);

/**
 * \brief Solicita un caracter al usuario y lo valida
 * \param input Se carga el caracter ingresado
 * \param message Es el mensaje a ser mostrado
 * \param eMessage Es el mensaje a ser mostrado en caso de error
 * \param lowLimit Limite inferior a validar
 * \param hiLimit Limite superior a validar
 * \return void
 */
void input_getChar(char* input, char message[], char eMessage[], char lowLimit, char hiLimit);

/**
 * \brief Solicita un caracter al usuario entre dos letras que representan un genero
 * \param input Se carga el caracter ingresado
 * \param message Es el mensaje a ser mostrado
 * \param eMessage Es el mensaje a ser mostrado en caso de error
 * \param lowLimit Primer genero
 * \param hiLimit Segundo genero
 * \return void
 */
void input_getCharGenero(char* input, char message[], char eMessage[], char lowLimit, char hiLimit);

/**
 * \brief Solicita una cadena de caracteres al usuario y la valida
 * \param input Se carga el string ingresado
 * \param message Es el mensaje a ser mostrado
 * \param eMessage Es el mensaje a ser mostrado en caso de error
 * \param lowLimit Longitud mínima de la cadena
 * \param hiLimit Longitud máxima de la cadena
 * \return void
 */
void input_getString(char* input, char message[], char eMessage[], int lowLimit, int hiLimit);

/**
 * \brief Solicita un caracter que sea "s" o "n"
 * \param respuesta Se carga el caracter ingresado
 * \param mensaje Es el mensaje a ser mostrado
 * \return void
 */
void input_getAnswer (char* respuesta, char mensaje[]);

void input_getName(char* input, char message[], char eMessage[], int lowLimit, int hiLimit);
