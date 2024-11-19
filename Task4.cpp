#include"Task4.h"

// добавление подмассивов по одному элементу
void singlesMass(Massiv<Massiv<int16_t>>& FindedSudMass, Massiv<int16_t> mass){
    for(size_t q = 0; q < mass.MLength(); q++){
        FindedSudMass.MPUSH({mass[q]});
    }
}

void linearMass(Massiv<Massiv<int16_t>>& FindedSudMass, Massiv<int16_t> mass){
    Massiv<int16_t> bfMas;
    bfMas.MPUSH(mass[0]);
    for(size_t q = 1; q < mass.MLength(); q++){
        bfMas.MPUSH(mass[q]);
        FindedSudMass.MPUSH(bfMas);
    }
}

void allLinearMass(Massiv<Massiv<int16_t>>& FindedSudMass, Massiv<int16_t> mass){
    Massiv<int16_t> bfMas;
    bfMas = mass;
    while(!bfMas.isEmpty()){
        linearMass(FindedSudMass, bfMas);
        bfMas.MPOP(0);
    }
}



Massiv<Massiv<int16_t>> AllSubMass(Massiv<int16_t> mass){
    Massiv<Massiv<int16_t>> FindedSudMass;
    
    singlesMass(FindedSudMass, mass);
    allLinearMass(FindedSudMass, mass);
    return FindedSudMass;
}

Massiv<Massiv<int16_t>> CorrectSubMass(Massiv<int16_t> mass, int16_t purpose){
    Massiv<Massiv<int16_t>> FindedSudMass = AllSubMass(mass);
    Massiv<Massiv<int16_t>> CorectMass;
    for(size_t q = 0; q < FindedSudMass.MLength(); q++){
        if(FindedSudMass[q].summ() == purpose){
            CorectMass.MPUSH(FindedSudMass[q]);
        }
    }
    return CorectMass;
}

template<typename gen_t>
std::ostream& operator<<(std::ostream& os, Massiv<Massiv<gen_t>> mass){
    for(size_t q = 0; q < mass.MLength(); q++){
        for(size_t p = 0; p < mass[q].MLength(); p++){
            os << mass[q][p] << ' ';
        }
        os << '\n';
    }
    return os;
}