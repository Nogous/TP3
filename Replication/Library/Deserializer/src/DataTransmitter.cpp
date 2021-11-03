// DataTransmitter.cpp : définit le point d'entrée de l'application.
//

#include "DataTransmitter.h"
#include "Serializer.h"
#include "framework.h"
#include "Player.h"
using namespace std;
using namespace uqac::network;
using namespace uqac::game;

int main()
{/*
	Serializer s = Serializer(10);
	
	char mystring[] = "sltlazonecommentcava";
	s.SerializeData(mystring);
	std::cout << "Buffer contains : " << s.GetBuffer().data() << std::endl;
	
	int myInt = 123456789;
	s.SerializeData(myInt);
	std::cout << "Buffer contains : " << s.GetBuffer().data() << std::endl;

	s.SerializeData(myFloat);
	std::cout << "Buffer contains : " << s.GetBuffer().data() << std::endl;*/

	Player player = Player(200, -9876.5f, Vector3(1, 3.456f, .543f), Quaternion());


	Player player2 = Player();
	player2.rotation.w = 2;

	player.armor = 2;
	player.size = Vector3(1, 3.456f, .5437234f);

	Serializer ser = Serializer(1);
	player.Write(ser);
	Deserializer deser = Deserializer();
	player2.Read(deser, ser.GetBuffer());

	std::cout << "-------Update-Player1--------" << std::endl;

	player.PrintPlayerData();
	std::cout << "-------Update-Player2--------" << std::endl;

	player2.PrintPlayerData();

	return 0;
}

