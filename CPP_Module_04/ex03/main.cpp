#include <iostream>
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

// void leaks(void)
// {
// 	system("leaks interfaces");
// }

int main()
{
    // leaks 검사
    // atexit(leaks);
    // MateriaSource 생성
    IMateriaSource* src = new MateriaSource();
	std::cout << std::endl;
    // Ice와 Cure 타입의 Materias를 학습
    src->LearnMateria(new Ice());
	std::cout << std::endl;

    src->LearnMateria(new Cure());
	std::cout << std::endl;

    // "me" 이름의 Character 생성
    ICharacter* me = new Character("me");
	std::cout << std::endl;

    // "bocal" 이름의 Character 생성
    ICharacter* bocal = new Character("bocal");
	std::cout << std::endl;

    // "cadet" 이름의 Character 생성
    ICharacter* cadet = new Character("cadet");
	std::cout << std::endl;

    // MateriaSource가 빈 상태에서 Materia를 생성하고 Equip 시도
    AMateria* tmp_ice = src->CreateMateria("ice"); // "ice" 타입의 Materia 생성
  	std::cout << std::endl;

    me->Equip(tmp_ice); // Character에 Materia 장착
    me->Use(0, *bocal); // 장착한 Materia를 bob에게 사용
    me->Use(0, *cadet); // 장착한 Materia를 alice에게 사용
	std::cout << std::endl;

    // MateriaSource에 존재하지 않는 타입의 Materia 생성 시도
    AMateria* tmp_fire = src->CreateMateria("fire"); // 존재하지 않는 "fire" 타입의 Materia 생성
	std::cout << std::endl;

    if (tmp_fire == NULL) {
        std::cout << "Unknown type: fire" << std::endl;
    }
	std::cout << std::endl;

    // 두 개의 Materia를 Equip한 Character가 또 다른 Materia를 Equip 시도
    AMateria* tmp_cure = src->CreateMateria("cure"); // "cure" 타입의 Materia 생성
	std::cout << std::endl;

    me->Equip(tmp_cure); // 이미 2개의 Materia가 장착되어 있으므로 Equip 실패
    me->Use(1, *bocal); // 장착하지 않은 인덱스(2)의 Materia 사용 시도
	std::cout << std::endl;

    // 한 Character가 다른 Character에게 Materia를 사용
    AMateria* tmp_cure2 = src->CreateMateria("cure"); // "cure" 타입의 Materia 생성
	std::cout << std::endl;

    me->Equip(tmp_cure2); // Character에 Materia 장착
    me->Use(2, *bocal); // 장착한 Materia를 bob에게 사용
    me->Use(2, *cadet); // 장착한 Materia를 alice에게 사용
	std::cout << std::endl;

    // Character가 Materia를 장착해제
	me->UnEquip(0); // 첫 번째 Materia 장착해제
    me->UnEquip(1); // 두 번째 Materia 장착해제
	std::cout << std::endl;

    // Character의 이름 확인
    std::cout << "Character name: " << me->GetName() << std::endl;
	std::cout << std::endl;

    // 메모리 해제]
	delete tmp_ice;
	std::cout << std::endl;
	delete tmp_cure;
	std::cout << std::endl;
    delete me;
	std::cout << std::endl;
    delete bocal;
	std::cout << std::endl;
    delete cadet;
	std::cout << std::endl;
    delete src;
	std::cout << std::endl;

    return 0;
}

// int main()
// {
//     atexit(leaks);
// 	IMateriaSource* src = new MateriaSource();
// 	ICharacter* me = new Character("me");
// 	ICharacter* bob = new Character("bob");
// 	AMateria* tmp_ice = NULL;
// 	AMateria* tmp_cure = NULL;
	
// 	src->LearnMateria(new Ice());
// 	src->LearnMateria(new Cure());
// 	tmp_ice = src->CreateMateria("ice");
// 	me->Equip(tmp_ice);
// 	tmp_cure = src->CreateMateria("cure");
// 	me->Equip(tmp_cure);
// 	me->Use(0, *bob);
// 	me->Use(1, *bob);
// 	me->UnEquip(0);
// 	me->UnEquip(1);
// 	delete tmp_ice;
// 	tmp_ice = NULL;
// 	delete tmp_cure;
// 	tmp_cure = NULL;
// 	delete bob;
// 	delete me;
// 	delete src;
// 	return 0;
// }

// int main()
// {
//  atexit(leaks);
// 	IMateriaSource* src = new MateriaSource();
// 	src->LearnMateria(new Ice());
// 	src->LearnMateria(new Cure());
// 	ICharacter* me = new Character("me");
// 	AMateria* tmp;
// 	tmp = src->CreateMateria("ice");
// 	me->Equip(tmp);
// 	tmp = src->CreateMateria("cure");
// 	me->Equip(tmp);
// 	ICharacter* bob = new Character("bob");
// 	me->Use(0, *bob);
// 	me->Use(1, *bob);
// 	delete bob;
// 	delete me;
// 	delete src;
// return 0;
// }