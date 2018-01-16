#ifndef __Map_hpp_
#define __Map_hpp_
#include <iostream>

using namespace std;

template <class Tklucz,class Twartosc> class Map {
  private:
    struct wezel{
      wezel* naprzod;
      Tklucz klucz;
      Twartosc wartosc;
      wezel()
      {
        naprzod = NULL;
      }
      wezel(const wezel& w){
        if(w.naprzod==NULL)
          naprzod=NULL;
        else{
          naprzod = w.naprzod;
        }
        klucz = w.klucz;
        wartosc = w.wartosc;
      }
      ~wezel()
      {
        //delete wartosc;
      }
    };
    wezel* start;

    void wyczysc()
    {
      if(start != NULL)
      {
        wezel* obecny,*nastepny;
        obecny = start;
        while(obecny != NULL)
        {
          nastepny = obecny->naprzod;
          delete obecny;
          obecny = nastepny;
        }
      }
    }

    void kopiuj(const Map& M)
    {
      wezel *zrodlo;
      wezel *cel;
      zrodlo = M.start;
      cel = new wezel(*zrodlo);
      start = cel;
      while(zrodlo)
      {
        zrodlo = zrodlo->naprzod;
        if(zrodlo == NULL)
        {
          cel->naprzod = NULL;
          break;
        }
        cel->naprzod = new wezel(*zrodlo);
        cel = cel->naprzod;
      }
    }
  public:
    Map()
    {
      start = NULL;
    }

    ~Map()
    {
      wyczysc();
    }

    Map(const Map& M)
    {
      kopiuj(M);
    }

    void Add(Tklucz klucz, Twartosc wartosc)
    {
      wezel* nowy = new wezel();
      nowy->naprzod = start;
      nowy->wartosc = wartosc;
      nowy->klucz = klucz;
      start = nowy;
    }

    Twartosc* Find(Tklucz klucz)
    {
      wezel* pomoc = start;
      while(pomoc)
      {
        if(pomoc->klucz == klucz)
          return &pomoc->wartosc;
        pomoc = pomoc->naprzod;
      }
      return NULL;
    }

    Map& operator=(const Map<class klasa1, class klasa2> & M)
    {
      Map<klasa1,klasa2> nowaMapa;
      nowaMapa.kopiuj(M);
      return nowaMapa;
    }

    friend std::ostream& operator << (std::ostream &s, const Map& M)
    {
      wezel* pomoc = M.start;
      while(pomoc)
      {
        s << pomoc->wartosc;
        pomoc = pomoc->naprzod;
      }
      return s;
    }
};

#endif
