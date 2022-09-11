/********************************************************************************
* main.cpp: Demonstration av funktionstemplates i C++.
********************************************************************************/
#include <iostream>
#include <vector>

/********************************************************************************
* vector_assign: Tilldelar data till angiven vektor med angivet stegv�rde,
*                d�r stegv�rde 1 utg�r default f�r inkrementering med ett.
*                Stegv�rdet utg�r differensen mellan varje element, allts�
*                om f�rsta elementet tilldelas 0 och vi har stegv�rdet 2, s�
*                tilldelas det andra elementet heltalet 2, n�sta 4 osv.
* 
*                - v   : Referens till vektorn som skall tilldelas.
*                - step: Stegv�rdet (default = 1).
********************************************************************************/
template<class T>
static void vector_assign(std::vector<T>& v, 
                          const T step = static_cast<T>(1))
{
   T num = static_cast<T>(0);

   for (auto& i : v)
   {
      i = num;
      num += step;
   }

   return;
}

/********************************************************************************
* vector_print: Skriver ut inneh�ll lagrat i angiven vektor via angiven utstr�m,
*               d�r standardutenheten std::cout anv�nds som default f�r utskrift
*               i terminalen.
*
*               - v      : Referens till vektorn som skall tilldelas.
*               - ostream: Referens till angiven utstr�m (default = std::cout). 
********************************************************************************/
template<class T> 
static void vector_print(const std::vector<T>& v,
                         std::ostream& ostream = std::cout)
{
   if (!v.size()) return;
   ostream << "--------------------------------------------------------------------------------\n";

   for (auto& i : v)
   {
      ostream << i << "\n";
   }

   ostream << "--------------------------------------------------------------------------------\n\n";
   return;
}

/********************************************************************************
* get_sum: Returnerar summan av angivna tal x och y.
* 
*          - x: F�rsta talet som skall summeras.
*          - y: Andra talet som skall summeras.
********************************************************************************/
template<class T1, class T2>
static inline auto get_sum(const T1 x,
                           const T2 y)
{
   return x + y;
}

/********************************************************************************
* main: Deklarerar en vektor v1, som rymmer f�r 20 heltal. Vektorn fylls med
*       20 heltal 0 - 19, vilket skrivs ut i terminalen. Sedan deklareras en
*       vektor v2, som rymmer 30 flyttal. Denna vektor fylls med 30 flyttal 
*       0 ned till -14.5 vilket skrivs ut i terminalen. Slutligen skrivs 
*       summan av tv� tal x = 3 samt y = 4.5 av olika datatyper ut via anrop
*       av den generiska funktionen get_sum.
********************************************************************************/
int main(void)
{
   std::vector<int> v1(20, 0);
   vector_assign(v1); 
   vector_print(v1); 

   std::vector<double> v2(30, 0);
   vector_assign(v2, -0.5);
   vector_print(v2);

   const auto x = 3;
   const auto y = 4.5;
   std::cout << x << " + " << y << " = " << get_sum(x, y) << "\n";

   return 0;
}