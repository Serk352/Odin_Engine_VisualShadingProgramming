#pragma once

#include <string.h>
#include <wchar.h>
#include "PrerequisitesUtil.h"

//#include <windows.h>


namespace OE_SDK
{

	template <typename T>
	using BasicString = std::basic_string<T, std::char_traits<T>, StdAlloc<T>>;


	template<typename T>
	using BasicStringStream = std::basic_stringstream<T, std::char_traits<T>, StdAlloc<T>>;


	typedef BasicString <UNICHAR> WString;

	typedef BasicString <ANSICHAR> String;

	typedef BasicStringStream <UNICHAR> WStringStream;

	typedef BasicStringStream <ANSICHAR> StringStream;




	class ODIN_ENGINE_UTILITY_EXPORT C_StringUtil
	{
		//)Todos los template deben estar declarados e implementados en el .h
	

		template <typename T>
		Vector<T> SplitInternal(T strData, T separator)
		{
			Vector<T> vTemp;

			//Set the initial position
			SIZE_T iniPos = 0;
			//Set the variable position in the place where he finds the token we want, in this case separator it's the token
			SIZE_T position = strData.find(separator, iniPos);

			//genera un ciclo, el cual mientras la posicion sea diferente a npos continuará
			//npos es un marcador que find regresa cuando no encuentra lo que se le pide
			while (position != strData.npos)
			{
				//Generamos el string temporal que guardará la cadena que meteremos al vector de cadenas
				//Este estring se igualará o en este string se guardará, un string que es parte del string principal
				//Esto se logra con el uso del método substring, el cual sustrae una porción del string.
				//Substr recibe la posición del primer carácter que copiará y el número de caracteres que vas a copiar
				T subStr = strData.substr(iniPos, position - iniPos);

				//Ahora la cadena es guardada en el vector que regresará el método
				vTemp.push_back(subStr);

				//Resetea la posición inicial, tomando la posición actual (donde encontro el token) y le suma el tamaño de caracteres del token
				iniPos = position + separator.length();

				//Resetea la posción, vuelve a igualarlo al lugar donde encuentre el siguiente token
				position = strData.find(separator, iniPos);
			}

			//Ahora que se han encontrado todos los token, se debe guardar la última cadena que se encuentra despues del último token
			//Se genera otra cadena en la cual se guarda un sustración de la cadena original, que va desde la última posición inicial a
			//el último caracter de la cadena original, esto se logra sacando el tamaño de la cadena y se le resta uno, los caracteres guardados
			//tiene ID que empiezan desde el 0
			T subStr = strData.substr(iniPos, strData.length() - iniPos);

			//Se guarda esta cadena en el vector de cadenas que debe  regresar el método
			vTemp.push_back(subStr);

			return vTemp;
		}

		Vector<String> Split(String strData, String separator)
		{
			return SplitInternal(strData, separator);
		}

		Vector<WString> Split(WString strData, WString separator)
		{
			//Pese a que se implementará en la función con template, es recomendable hacerlo en una definida como la actual,
			//para que aparezcan las sugerencias de Intellisense, en template al no tener un tipo específico, no sabe que sugencias hacer.
			return SplitInternal(strData, separator);
		}

		template <typename T>
		BasicString<T> TrimInternal(BasicString<T> strData)
		{
			//El método de Trim, tiene la función de quitar todos los espacios al inicio de la cadena y al final de esta
			//Recibe una cadena y regresa una nueva cadena

			//Creamos una cadena temporal que será la que regresemos en este método
			BasicString<T> sTemp;

			//Lo utilizamos para saber donde va a empezar la nueva cadena
			SIZE_T initPos;
			//Lo utilizamos para saber donde va a terminar la nueva cadena
			SIZE_T finPos;
			//Lo que haremos será contar los espacios al inicio, luego contar los espacios al final, y entonces hacer una sustracción del string
			//Original y guardarlo en el de retorno con las coordenadas que sacamos


			//Con este ciclo empezamos a contar los espacios desde el inicio de la cadena hasta que encuentre un caracter diferente al espacio
			for (int i = 0; i < strData.length() - 1; ++i)
			{
				if (strData[i] == ' ')
				{
					initPos++;
				}
				else
				{
					break;
				}
			}

			//Con este ciclo empezamos a contar los espacios que hay desde el final de la cadena, hacía atras hasta encontrar un carácter diferente
			for (int i = strData.length() - 1; i >= 0; --i)
			{
				if (strData[i] == ' ')
				{
					finPos++;
				}
				else
				{
					break;
				}
			}

			//Ahora guardamos en nuestra cadena temporal una cadena, cadena que sustraemos de la cadena recibida, la cual empezará desde la posición inicial
			//hasta el largo de la cadena recibida menos la posición final
			sTemp = strData.substr(initPos, ((strData.length() - 1) - finPos));


			//Retornamos la cadena temporal.
			return sTemp;

		}

		template<typename T>
		BasicString<T> Trim(BasicString<T> strData)
		{

		/*	//El método de Trim, tiene la función de quitar todos los espacios al inicio de la cadena y al final de esta
			//Recibe una cadena y regresa una nueva cadena

			//Creamos una cadena temporal que será la que regresemos en este método
			String sTemp;

			//Lo utilizamos para saber donde va a empezar la nueva cadena
			SIZE_T initPos;
			//Lo utilizamos para saber donde va a terminar la nueva cadena
			SIZE_T finPos;
			//Lo que haremos será contar los espacios al inicio, luego contar los espacios al final, y entonces hacer una sustracción del string
			//Original y guardarlo en el de retorno con las coordenadas que sacamos


			//Con este ciclo empezamos a contar los espacios desde el inicio de la cadena hasta que encuentre un caracter diferente al espacio
			for (int i = 0; i < strData.length() - 1; ++i)
			{
				if (strData[i] == ' ')
				{
					initPos++;
				}
				else
				{
					break;
				}
			}

			//Con este ciclo empezamos a contar los espacios que hay desde el final de la cadena, hacía atras hasta encontrar un carácter diferente
			for (int i = strData.length() - 1; i >= 0; --i)
			{
				if (strData[i] == ' ')
				{
					finPos++;
				}
				else
				{
					break;
				}
			}


			//Ahora guardamos en nuestra cadena temporal una cadena, cadena que sustraemos de la cadena recibida, la cual empezará desde la posición inicial
			//hasta el largo de la cadena recibida menos la posición final
			sTemp = strData.substr(initPos, ((strData.length()-1) -finPos));


			//Retornamos la cadena temporal.
			return sTemp;*/

			return TrimInternal<T>(strData);
		}

		template<typename T>
		BasicString<T> ToUpper(BasicString<T> strData)
		{
			//creamos una cadena temporal que será la que regresaremos
			BasicString<T> stemp(strData);
			std::transform(stemp.begin(), stemp.end(), str.begin(), std::toupper);
			return stemp;
		}

		template<typename T>
		BasicString<T> ToLower(BasicString<T> strData)
		{
			//creamos una cadena temporal que será la que regresaremos
			BasicString<T> stemp(strData);
			std::transform(stemp.begin(), stemp.end(), str.begin(), std::tolower);
			return stemp;
		}

	
	};

}
