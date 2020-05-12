#ifndef TEST_H
#define TEST_H

#if defined(_WIN32)
#  if defined(EXPORTING_TEST)
#    define DECLSPEC __declspec(dllexport)
#  else
#    define DECLSPEC __declspec(dllimport)
#  endif
#else // non windows
#  define DECLSPEC
#endif

namespace testLib {
    void DECLSPEC test();
}


#endif //TEST_H