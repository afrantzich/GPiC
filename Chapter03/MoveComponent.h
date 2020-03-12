// ----------------------------------------------------------------
// From Game Programming in C++ by Sanjay Madhav
// Copyright (C) 2017 Sanjay Madhav. All rights reserved.
// 
// Released under the BSD License
// See LICENSE in root directory for full details.
// ----------------------------------------------------------------

#pragma once
#include "Component.h"

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
	float GetSumForces() const { return mSumForces; }
	float GetVelocity() const { return mVelocity; }
	void SetMass(float mass) { mMass = mass; }
	void SetVelocity(float vel) { mVelocity = vel; }
	void AddForce(float force) { mSumForces += force; }

private:
	// Controls rotation (radians/second)
	float mAngularSpeed;
	// Controls forward movement (units/second)
	float mForwardSpeed;

	// Newtonian physics
	float mMass;
	float mSumForces;
	float mVelocity;
};
