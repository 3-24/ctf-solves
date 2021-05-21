#include <stdio.h>
#include <string.h>

char result[56] = {0x1a, 0x97, 0xaf, 0x14, 0x49, 0x79, 0x16, 0x1a, 0xf4,0xde, 0xe8, 0xd3, 0x16,0x66,0xdc,0x25,0xff,0x46,0x26,0x64,3,0x6a,0xc9,0xfc,0x19,0x1b,0x20,0x33,0xe9,0xf7,0x1d,0xdc,0xd,0x62,0xc8,0x8a,0x26,0x3f,0xdf,0x5d,0x44,0x0e,0x55,0x3d,6,0xdb,0xe0,0xc5,0x93,0x2d,0x2c,0x80,5,0xb5,0xd8,0xfc};

void ifunc19(){
    for (int i=55;i>=42;--i){
        *(&result[i]) -= 0x38*0x3a;
    }

    for (int i=41;i>=28;--i){
        result[i] -= 0x3a*0x34;
    }

    for (int i=27;i>=14; --i){
        result[i] -= 0x34*0x39;
    }

    for (int i = 13; i>=0; --i){
        result[i] -= 0x35 * 0x33;
    }
}

void ifunc18(){
    for (int i=55;i>=42;--i){
        *(&result[i]) -= 0x33*0x32;
    }

    for (int i=41;i>=28;--i){
        result[i] -= 0x33*0x31;
    }

    for (int i=27;i>=14; --i){
        result[i] -= 0x31*0x38;
    }

    for (int i = 13; i>=0; --i){
        result[i] -= 0x36* 0x39;
    }
}

void ifunc17(){
    for (int i=55;i>=42;--i){
        result[i] -= 0x35*0x37;
    }

    for (int i=41;i>=28;--i){
        result[i] -= 0x37*0x36;
    }

    for (int i=27;i>=14; --i){
        result[i] -= 0x3a*0x38;
    }

    for (int i = 13; i>=0; --i){
        result[i] -= 0x36* 0x38;
    }
}

void ifunc16(){
    for (int i=55;i>=42;--i){
        result[i] -= 0x34*0x32;
    }

    for (int i=41;i>=28;--i){
        result[i] -= 0x35*0x36;
    }

    for (int i=27;i>=14; --i){
        result[i] -= 0x32*0x31;
    }

    for (int i = 13; i>=0; --i){
        result[i] -= 0x34* 0x39;
    }
}

void ifunc15(){
    for (int i=55;i>=42;--i){
        result[i] -= 0x37*0x35;
    }

    for (int i=41;i>=28;--i){
        result[i] -= 0x31*0x39;
    }

    for (int i=27;i>=14; --i){
        result[i] -= 0x33*0x3a;
    }

    for (int i = 13; i>=0; --i){
        result[i] -= 0x37+0x33;
    }
}

char aVeteranssantar[19] = "veteranssantarudolf";
char aSled[4] = "sled";
char aDragonfour[10] = "dragonfour";
char aHerosoldier[11] = "herosoldier";
char s[17] = "armywarriorknight";
char aWarriorknight[13] = "warriorknight";
char aKnight[6] = "knight";


void ifunc14(){
    for (int i=55;i>=42;--i){
        result[i] ^= (aVeteranssantar[i % strlen(aVeteranssantar)] | s[i%strlen(aWarriorknight)+4]);
    }

    for (int i=41;i>=28;--i){
        result[i] ^=(s[i % strlen(s)] | aHerosoldier[i % strlen(aHerosoldier)]);
    }

    for (int i=27;i>=14; --i){
        result[i] ^= (aVeteranssantar[i % strlen(&aVeteranssantar[13])+13] | aDragonfour[i % strlen(aDragonfour)]);
    }

    for (int i = 13; i>=0; --i){
        result[i] ^= (s[i%strlen(aKnight) + 11] | aHerosoldier[i%strlen(&aHerosoldier[4])+4]);
    }
}

void ifunc13(){
    for (int i=55;i>=42;--i){
        result[i] ^= (aVeteranssantar[i % strlen(&aVeteranssantar[8])+8] | aVeteranssantar[i % strlen(&aVeteranssantar[13])+13]);
    }

    for (int i=41;i>=28;--i){
        result[i] ^= (aHerosoldier[i % strlen(aHerosoldier)] | aSled[i % strlen(aSled)]);
    }

    for (int i=27;i>=14; --i){
        result[i] ^= (s[i % strlen(s)] | aDragonfour[i%strlen(aDragonfour)]);
    }

    for (int i = 13; i>=0; --i){
        result[i] ^= (aHerosoldier[i % strlen(&aHerosoldier[4] + 4)] | aVeteranssantar[i % strlen(aVeteranssantar)]);
    }
}

void ifunc12(){
    for (int i=55;i>=42;--i){
        result[i] ^= (aHerosoldier[i % strlen(&aHerosoldier[4])+4] | s[i%strlen(aKnight) + 11]);
    }

    for (int i=41;i>=28;--i){
        result[i] ^= (aSled[i % strlen(aSled)] | s[i%strlen(aWarriorknight)+4]);
    }

    for (int i=27;i>=14; --i){
        result[i] ^= (s[i % strlen(aWarriorknight)+4] | aSled[i%strlen(aSled)]);
    }

    for (int i = 13; i>=0; --i){
        result[i] ^= (aVeteranssantar[i % strlen(&aVeteranssantar[13])+13] | aVeteranssantar[i % strlen(&aVeteranssantar[8])+8]);
    }
}

void ifunc11(){
    for (int i=55;i>=42;--i){
        result[i] ^= (s[i%strlen(s)] | s[i%strlen(aKnight)+11]);
    }

    for (int i=41;i>=28;--i){
        result[i] ^= (aVeteranssantar[i % strlen(aVeteranssantar)] | aHerosoldier[i % strlen(aHerosoldier)]);
    }

    for (int i=27;i>=14; --i){
        result[i] ^= (aVeteranssantar[i % strlen(&aVeteranssantar[8])+8] | aVeteranssantar[i % strlen(&aVeteranssantar[8])+8]);
    }

    for (int i = 13; i>=0; --i){
        result[i] ^= (aDragonfour[i % strlen(aDragonfour)] | aDragonfour[i%strlen(aDragonfour)]);
    }
}

void ifunc10_1(){
    for (int i=55;i>=42;--i){
        result[i] ^= (s[i%strlen(aWarriorknight)+4] | aVeteranssantar[i % strlen(aVeteranssantar)]);
    }

    for (int i=41;i>=28;--i){
        result[i] ^= (s[i % strlen(aKnight)+11] | aHerosoldier[i % strlen(aHerosoldier)]);
    }

    for (int i=27;i>=14; --i){
        result[i] ^= (aSled[i % strlen(aSled)] | aHerosoldier[i % strlen(&aHerosoldier[4])+4]);
    }

    for (int i = 13; i>=0; --i){
        result[i] ^= (s[i%strlen(s)] | aVeteranssantar[i % strlen(&aVeteranssantar[13])+13]);
    }
}

void ifunc10(){
    ifunc10_1();
    for (int i=55;i>=42;--i){
        result[i] ^= 0x37;
    }

    for (int i=41;i>=28;--i){
        result[i] ^= 0x33;
    }

    for (int i=27;i>=14; --i){
        result[i] ^= 0x39;
    }

    for (int i = 13; i>=0; --i){
        result[i] ^= 0x35;
    }
}

void ifunc8();

void ifunc9(){
    for (int i=55;i>=42;--i){
        result[i] ^= 0x34;
    }

    for (int i=41;i>=28;--i){
        result[i] ^= 0x31;
    }

    for (int i=27;i>=14; --i){
        result[i] ^= 0x36;
    }

    for (int i = 13; i>=0; --i){
        result[i] ^= 0x32;
    }
    ifunc8();
}

void ifunc8(){
    for (int i=55;i>=42;--i){
        result[i] -= 0x38;
    }

    for (int i=41;i>=28;--i){
        result[i] -= 0x3a;
    }

    for (int i=27;i>=14; --i){
        result[i] -= 0x36;
    }

    for (int i = 13; i>=0; --i){
        result[i] -= 0x37;
    } 
}

void ifunc7(){
    ifunc9();
    for (int i=55;i>=42;--i){
        result[i] -= 0x39;
    }

    for (int i=41;i>=28;--i){
        result[i] -= 0x31;
    }

    for (int i=27;i>=14; --i){
        result[i] -= 0x33;
    }

    for (int i = 13; i>=0; --i){
        result[i] -= 0x32;
    }
}

void ifunc6(){
    for (int i=55;i>=42;--i){
        result[i] -= 0x35;
    }

    for (int i=41;i>=28;--i){
        result[i] -= 0x34;
    }

    for (int i=27;i>=14; --i){
        result[i] -= 0x3a;
    }

    for (int i = 13; i>=0; --i){
        result[i] -= 0x38;
    }
}

void ifunc5(){
    for (int i=55;i>=42;--i){
        result[i] ^= aHerosoldier[i%strlen(&aHerosoldier[4])+4];
    }

    for (int i=41;i>=28;--i){
        result[i] ^= aSled[i % strlen(aSled)];
    }

    for (int i=27;i>=14; --i){
        result[i] ^= s[i%strlen(aWarriorknight)+4];
    }

    for (int i = 13; i>=0; --i){
        result[i] ^= aVeteranssantar[i % strlen(&aVeteranssantar[13])+13];
    }
}

void ifunc4(){
    ifunc7();
    for (int i=55;i>=42;--i){
        result[i] ^= s[i%strlen(s)];
    }

    for (int i=41;i>=28;--i){
        result[i] ^= aHerosoldier[i % strlen(aHerosoldier)];
    }

    for (int i=27;i>=14; --i){
        result[i] ^= aVeteranssantar[i % strlen(&aVeteranssantar[8])+8];
    }

    for (int i = 13; i>=0; --i){
        result[i] ^= aDragonfour[i % strlen(aDragonfour)];
    }
}

void ifunc3(){
    ifunc4();
    for (int i=55;i>=42;--i){
        result[i] ^= s[i % strlen(aKnight) + 11];
    }

    for (int i=41;i>=28;--i){
        result[i] ^= aVeteranssantar[i % strlen(aVeteranssantar)];
    }

    for (int i=27;i>=14; --i){
        result[i] ^= aVeteranssantar[i % strlen(&aVeteranssantar[8])+8];
    }

    for (int i = 13; i>=0; --i){
        result[i] ^= aDragonfour[i % strlen(aDragonfour)];
    }
}

void ifunc2(){
    ifunc3();
    for (int i=55;i>=42;--i){
        result[i] ^= s[i%strlen(aWarriorknight)+4];
    }

    for (int i=41;i>=28;--i){
        result[i] ^= s[i % strlen(aKnight) + 11];
    }

    for (int i=27;i>=14; --i){
        result[i] ^=  aHerosoldier[i % strlen(&aHerosoldier[4])+4];
    }

    for (int i = 13; i>=0; --i){
        result[i] ^= aVeteranssantar[i % strlen(&aVeteranssantar[13]) + 13];
    }
}

void ifunc1(){
    ifunc2();
    for (int i=55;i>=42;--i){
        result[i] ^= aVeteranssantar[i % strlen(aVeteranssantar)];
    }

    for (int i=41;i>=28;--i){
        result[i] ^= aHerosoldier[i % strlen(aHerosoldier)];
    }

    for (int i=27;i>=14; --i){
        result[i] ^=  aSled[i % strlen(aSled)];
    }

    for (int i = 13; i>=0; --i){
        result[i] ^= s[ i % strlen(s)];
    }
}

int main(){
    ifunc19();
    ifunc18();
    ifunc17();
    ifunc16();
    ifunc15();
    ifunc14();
    ifunc13();
    ifunc12();
    ifunc11();
    ifunc10();
    ifunc9();
    ifunc8();
    ifunc7();
    ifunc6();
    ifunc5();
    ifunc4();
    ifunc3();
    ifunc2();
    ifunc1();
    printf("%s",result);
    return 0;
}