// ----------------------------------------------------------------
// From Game Programming in C++ by Sanjay Madhav
// Copyright (C) 2017 Sanjay Madhav. All rights reserved.
// 
// Released under the BSD License
// See LICENSE in root directory for full details.
// ----------------------------------------------------------------

#pragma once
#include "Component.h"
#include "Math.h"

class MoveComponent : public Component
{
public:
	// Lower update order to update first
	MoveComponent(class Actor* owner, int updateOrder = 10);

	void Update(float deltaTime) override;
	
	float GetAngularSpeed() const { return mAngularSpeed; }
	float GetForwardSpeed() const { return mForwardSpeed; }
	void SetAngularSpeed(float speed) { mAngularSpeed = speed; }
	void SetForwardSpeed(float speed) { mForwardSpeed = speed; }

	// Newtonian
	float GetMass() const { return mMass; }
	Vector2 GetSumForces() const { return mSumForces; }
	Vector2 GetVelocity() const { return mVelocity; }
	void SetMass(float mass) { mMass = mass; }
	void SetVelocity(Vector2 vel) { mVelocity = vel; }
	void AddForce(Vector2 force) { mSumForces += force; }

private:
	// Controls rotation (radians/second)
	float mAngularSpeed;
	// Controls forward movement (units/second)
	float mForwardSpeed;

	// Newtonian physics
	float mMass;
	Vector2 mSumForces;
	Vector2 mVelocity;

	float mAsteroidColl;
};
