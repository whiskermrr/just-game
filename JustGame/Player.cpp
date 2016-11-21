#include "Player.h"


Player::Player(BulletHandler* bulletHandler)
{
	this->LoadTexture("soldier.png");
	this->source.x = 0;
	this->source.y = DOWN;
	this->setTextureRect(sf::IntRect(this->source.x * 64, this->source.y * 64, 64, 64));
	this->setPosition(600, 150);
	this->bulletHandler = bulletHandler;

	this->rangeWeapon = new RangeWeapon(this->bulletHandler, this->getPosition());
	this->rangeWeapon->loadTexture("bullet.png");
}

void Player::Update()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		this->source.y = UP;
		this->velocity.y = -2;
		source.x++;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		this->source.y = DOWN;
		this->velocity.y = 2;
		source.x++;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		this->source.y = RIGHT;
		this->velocity.x = 2;
		source.x++;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		this->source.y = LEFT;
		this->velocity.x = -2;
		source.x++;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) // trzeba zmienic!
	{
		this->rangeWeapon->shot();
	}

	if (!(sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::D) ||
		  sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::A)))
	{
		source.x = 0;
	}

	if (source.x * 64 >= 576)
		source.x = 0;

	this->setTextureRect(sf::IntRect(this->source.x * 64, this->source.y * 64, 64, 64));

	this->rangeWeapon->setPosition(this->getPosition());
	this->rangeWeapon->Update();
	Entity::Update();

	this->velocity.x = 0;
	this->velocity.y = 0;
}

void Player::Render(sf::RenderWindow* window)
{
	window->draw(*this);
	window->draw(*this->rangeWeapon);
}

Player::~Player()
{
	delete this->rangeWeapon;
	this->rangeWeapon = NULL;
	this->bulletHandler = NULL;
}
