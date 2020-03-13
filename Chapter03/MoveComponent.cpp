// ----------------------------------------------------------------
// From Game Programming in C++ by Sanjay Madhav
// Copyright (C) 2017 Sanjay Madhav. All rights reserved.
// 
// Released under the BSD License
// See LICENSE in root directory for full details.
// ----------------------------------------------------------------

#include "MoveComponent.h"
#include "Actor.h"
#include <iostream>

MoveComponent::MoveComponent(class Actor* owner, int updateOrder)
	:Component(owner, updateOrder)
	, mAngularSpeed(0.0f)
	, mForwardSpeed(0.0f)
	, mMass(0.05f)
	, mSumForces(Vector2 (0.0f, 0.0f))
	, mVelocity(Vector2 (0.0f, 0.0f))
{
	
}

void MoveComponent::Update(float deltaTime)
{
	
	// Gravity
	/*
	if (mMass > 0.01f)
	{
		AddForce(Vector2 (0.0f, 20.0f));
	}
	*/
	
	if (!Math::NearZero(mAngularSpeed))
	{
		float rot = mOwner->GetRotation();
		rot += mAngularSpeed * deltaTime;
		mOwner->SetRotation(rot);
	}
	
	Vector2 pos = mOwner->GetPosition();
	// calc acc from forces, velocity from acc, and pos from velocity
	// velocity, acc, force, and position are all vectors
	Vector2 acc = mSumForces * ( 1 / mMass );
	mVelocity += acc * deltaTime;
	pos += mVelocity * deltaTime;

	//pos += mOwner->GetForward() * mForwardSpeed * deltaTime;
		
	// (Screen wrapping code only for asteroids)
	if (pos.x < 0.0f) { pos.x = 1022.0f; }
	else if (pos.x > 1024.0f) { pos.x = 2.0f; }

	if (pos.y < 0.0f) { pos.y = 766.0f; }
	//else if (pos.y > 766.0f) { pos.y = 0.0f; }
	
	//  Sticky floor
	/*
	else if (pos.y >= 764.0f && mMass > 0.01f) { 
		pos.y = 764.0f;
		// Stop downward velocity
		mVelocity.y = 0.0f;
		// Deteriorate sideways motion while on ground
		mVelocity.x /= 1.05f;
	}
	*/
	

	mSumForces = Vector2(0.0f, 0.0f);
	mOwner->SetPosition(pos);
}
