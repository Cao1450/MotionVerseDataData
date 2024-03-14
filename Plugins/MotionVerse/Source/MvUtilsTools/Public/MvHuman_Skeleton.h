// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class MVUTILSTOOLS_API MvHuman_Skeleton
{
public:
	MvHuman_Skeleton(){}
	~MvHuman_Skeleton(){}


public:
	
	const TArray<FString> BodyBones_22 = {
			"Hips",//Hips
			"LeftUpLeg",//LeftUpperLeg
			"RightUpLeg",//RightUpperLeg
			"LeftLeg",//LeftLowerLeg
			"RightLeg",//RightLowerLeg
			"LeftFoot",//LeftFoot
			"RightFoot",//RightFoot
			"Spine",//Spine
			"Spine1",//Chest
			"Neck",//Neck
			"Head",//Head
			"LeftShoulder",//LeftShoulder
			"RightShoulder",//RightShoulder
			"LeftArm",//LeftUpperArm
			"RightArm",//RightUpperArm
			"LeftForeArm",//LeftLowerArm
			"RightForeArm",//RightLowerArm
			"LeftHand",//LeftHand
			"RightHand",//RightHand
			"LeftToeBase",//LeftToes
			"RightToeBase",//RightToes
			"Spine2",//UpperChest
	};

	const TArray<FString> BodyBonesWithRot = {
		"Hips",//Hips
		"LeftUpLeg",//LeftUpperLeg
		"RightUpLeg",//RightUpperLeg
		"LeftLeg",//LeftLowerLeg
		"RightLeg",//RightLowerLeg
		"LeftFoot",//LeftFoot
		"RightFoot",//RightFoot
		"Spine",//Spine
		"Spine1",//Chest
		"Neck",//Neck
		"Head",//Head
		"LeftShoulder",//LeftShoulder
		"RightShoulder",//RightShoulder
		"LeftArm",//LeftUpperArm
		"RightArm",//RightUpperArm
		"LeftForeArm",//LeftLowerArm
		"LeftForeArm1",
		"RightForeArm",//RightLowerArm
		"RightForeArm1",
		"LeftHand",//LeftHand
		"RightHand",//RightHand
		"LeftToeBase",//LeftToes
		"RightToeBase",//RightToes
		"Spine2",//UpperChest
	};
	const TArray<FString> HandBones_30 = {
		"LeftHandThumb1",//LeftThumbProximal
		"LeftHandThumb2",//LeftThumbIntermediate
		"LeftHandThumb3",//LeftThumbDistal
		"LeftHandIndex1",//LeftIndexProximal
		"LeftHandIndex2",//LeftIndexIntermediate
		"LeftHandIndex3",//LeftIndexDistal
		"LeftHandMiddle1",//LeftMiddleProximal
		"LeftHandMiddle2",//LeftMiddleIntermediate
		"LeftHandMiddle3",//LeftMiddleDistal
		"LeftHandRing1",//LeftRingProximal
		"LeftHandRing2",//LeftRingIntermediate
		"LeftHandRing3",//LeftRingDistal
		"LeftHandPinky1",//LeftLittleProximal
		"LeftHandPinky2",//LeftLittleIntermediate
		"LeftHandPinky3",//LeftLittleDistal
		"RightHandThumb1",//RightThumbProximal
		"RightHandThumb2",//RightThumbIntermediate
		"RightHandThumb3",//RightThumbDistal
		"RightHandIndex1",//RightIndexProximal
		"RightHandIndex2",//RightIndexIntermediate
		"RightHandIndex3",//RightIndexDistal
		"RightHandMiddle1",//RightMiddleProximal
		"RightHandMiddle2",//RightMiddleIntermediate
		"RightHandMiddle3",//RightMiddleDistal
		"RightHandRing1",//RightRingProximal
		"RightHandRing2",//RightRingIntermediate
		"RightHandRing3",//RightRingDistal
		"RightHandPinky1",//RightLittleProximal
		"RightHandPinky2",//RightLittleIntermediate
		"RightHandPinky3",//RightLittleDistal
	};
	
	//metaHuman
	const TArray<FString> BodyBones_22_MetaHuman{
			"pelvis",//Hips
			"thigh_l",//LeftUpperLeg
			"thigh_r",//RightUpperLeg
			"calf_l",//LeftLowerLeg
			"calf_r",//RightLowerLeg
			"foot_l",//LeftFoot
			"foot_r",//RightFoot
			"spine_01",//Spine
			"spine_03",//Chest
			"neck_01",//Neck
			"head",//Head
			"clavicle_l",//LeftShoulder
			"clavicle_r",//RightShoulder
			"upperarm_l",//LeftUpperArm
			"upperarm_r",//RightUpperArm
			"lowerarm_l",//LeftLowerArm
			"lowerarm_r",//RightLowerArm
			"hand_l",//LeftHand
			"hand_r",//RightHand
			"ball_l",//LeftToes
			"ball_r",//RightToes
			"spine_05",//UpperChest
	};
	
	const TArray<FString> HandBones_30_MetaHuman = {
			"thumb_01_l",//LeftThumbProximal
			"thumb_02_l",//LeftThumbIntermediate
			"thumb_03_l",//LeftThumbDistal
			"index_01_l",//LeftIndexProximal
			"index_02_l",//LeftIndexIntermediate
			"index_03_l",//LeftIndexDistal
			"middle_01_l",//LeftMiddleProximal
			"middle_02_l",//LeftMiddleIntermediate
			"middle_03_l",//LeftMiddleDistal
			"ring_01_l",//LeftRingProximal
			"ring_02_l",//LeftRingIntermediate
			"ring_03_l",//LeftRingDistal
			"pinky_01_l",//LeftLittleProximal
			"pinky_02_l",//LeftLittleIntermediate
			"pinky_03_l",//LeftLittleDistal
			"thumb_01_r",//RightThumbProximal
			"thumb_02_r",//RightThumbIntermediate
			"thumb_03_r",//RightThumbDistal
			"index_01_r",//RightIndexProximal
			"index_02_r",//RightIndexIntermediate
			"index_03_r",//RightIndexDistal
			"middle_01_r",//RightMiddleProximal
			"middle_02_r",//RightMiddleIntermediate
			"middle_03_r",//RightMiddleDistal
			"ring_01_r",//RightRingProximal
			"ring_02_r",//RightRingIntermediate
			"ring_03_r",//RightRingDistal
			"pinky_01_r",//RightLittleProximal
			"pinky_02_r",//RightLittleIntermediate
			"pinky_03_r",//RightLittleDistal
	};

	const TArray<FString> Body_Hand_Bones_52_MetaHuman{
		"pelvis",//Hips
		"thigh_l",//LeftUpperLeg
		"thigh_r",//RightUpperLeg
		"calf_l",//LeftLowerLeg
		"calf_r",//RightLowerLeg
		"foot_l",//LeftFoot
		"foot_r",//RightFoot
		"spine_01",//Spine
		"spine_03",//Chest
		"neck_01",//Neck
		"head",//Head
		"clavicle_l",//LeftShoulder
		"clavicle_r",//RightShoulder
		"upperarm_l",//LeftUpperArm
		"upperarm_r",//RightUpperArm
		"lowerarm_l",//LeftLowerArm
		"lowerarm_r",//RightLowerArm
		"hand_l",//LeftHand
		"hand_r",//RightHand
		"ball_l",//LeftToes
		"ball_r",//RightToes
		"spine_05",//UpperChest

		"thumb_01_l",//LeftThumbProximal
		"thumb_02_l",//LeftThumbIntermediate
		"thumb_03_l",//LeftThumbDistal
		"index_01_l",//LeftIndexProximal
		"index_02_l",//LeftIndexIntermediate
		"index_03_l",//LeftIndexDistal
		"middle_01_l",//LeftMiddleProximal
		"middle_02_l",//LeftMiddleIntermediate
		"middle_03_l",//LeftMiddleDistal
		"ring_01_l",//LeftRingProximal
		"ring_02_l",//LeftRingIntermediate
		"ring_03_l",//LeftRingDistal
		"pinky_01_l",//LeftLittleProximal
		"pinky_02_l",//LeftLittleIntermediate
		"pinky_03_l",//LeftLittleDistal
		"thumb_01_r",//RightThumbProximal
		"thumb_02_r",//RightThumbIntermediate
		"thumb_03_r",//RightThumbDistal
		"index_01_r",//RightIndexProximal
		"index_02_r",//RightIndexIntermediate
		"index_03_r",//RightIndexDistal
		"middle_01_r",//RightMiddleProximal
		"middle_02_r",//RightMiddleIntermediate
		"middle_03_r",//RightMiddleDistal
		"ring_01_r",//RightRingProximal
		"ring_02_r",//RightRingIntermediate
		"ring_03_r",//RightRingDistal
		"pinky_01_r",//RightLittleProximal
		"pinky_02_r",//RightLittleIntermediate
		"pinky_03_r",//RightLittleDistal
	};

	//树形结构按顺序，深度优先
	const TArray<FString> DM_Bones52_Order{
		"Hips",//Hips
		
		"LeftUpLeg",//LeftUpperLeg
		"LeftLeg",//LeftLowerLeg
		"LeftFoot",//LeftFoot
		"LeftToeBase",//LeftToes
		
		"RightUpLeg",//RightUpperLeg
		"RightLeg",//RightLowerLeg
		"RightFoot",//RightFoot
		"RightToeBase",//RightToes
		
		"Spine",//Spine
		"Spine1",//Chest
		"Spine2",//UpperChest
		"Neck",//Neck
		"Head",//Head
		
		"LeftShoulder",//LeftShoulder
		"LeftArm",//LeftUpperArm
		"LeftForeArm",//LeftLowerArm
		"LeftHand",//LeftHand
		"LeftHandThumb1",//LeftThumbProximal
		"LeftHandThumb2",//LeftThumbIntermediate
		"LeftHandThumb3",//LeftThumbDistal
		"LeftHandIndex1",//LeftIndexProximal
		"LeftHandIndex2",//LeftIndexIntermediate
		"LeftHandIndex3",//LeftIndexDistal
		"LeftHandMiddle1",//LeftMiddleProximal
		"LeftHandMiddle2",//LeftMiddleIntermediate
		"LeftHandMiddle3",//LeftMiddleDistal
		"LeftHandRing1",//LeftRingProximal
		"LeftHandRing2",//LeftRingIntermediate
		"LeftHandRing3",//LeftRingDistal
		"LeftHandPinky1",//LeftLittleProximal
		"LeftHandPinky2",//LeftLittleIntermediate
		"LeftHandPinky3",//LeftLittleDistal

		"RightShoulder",//RightShoulder
		"RightArm",//RightUpperArm
		"RightForeArm",//RightLowerArm
		"RightHand",//RightHand
		"RightHandThumb1",//RightThumbProximal
		"RightHandThumb2",//RightThumbIntermediate
		"RightHandThumb3",//RightThumbDistal
		"RightHandIndex1",//RightIndexProximal
		"RightHandIndex2",//RightIndexIntermediate
		"RightHandIndex3",//RightIndexDistal
		"RightHandMiddle1",//RightMiddleProximal
		"RightHandMiddle2",//RightMiddleIntermediate
		"RightHandMiddle3",//RightMiddleDistal
		"RightHandRing1",//RightRingProximal
		"RightHandRing2",//RightRingIntermediate
		"RightHandRing3",//RightRingDistal
		"RightHandPinky1",//RightLittleProximal
		"RightHandPinky2",//RightLittleIntermediate
		"RightHandPinky3",//RightLittleDistal
	};
	
	//树形结构按顺序，深度优先
	const TArray<FString> UE_Bones52_Order{
		"pelvis",//Hips
		
		"thigh_l",//LeftUpperLeg
		"calf_l",//LeftLowerLeg
		"foot_l",//LeftFoot
		"ball_l",//LeftToes
		
		"thigh_r",//RightUpperLeg
		"calf_r",//RightLowerLeg
		"foot_r",//RightFoot
		"ball_r",//RightToes
		
		"spine_01",//Spine
		"spine_03",//Chest
		"spine_05",//UpperChest
		"neck_01",//Neck
		"head",//Head
		
		"clavicle_l",//LeftShoulder
		"upperarm_l",//LeftUpperArm
		"lowerarm_l",//LeftLowerArm
		"hand_l",//LeftHand
		"thumb_01_l",//LeftThumbProximal
		"thumb_02_l",//LeftThumbIntermediate
		"thumb_03_l",//LeftThumbDistal
		"index_01_l",//LeftIndexProximal
		"index_02_l",//LeftIndexIntermediate
		"index_03_l",//LeftIndexDistal
		"middle_01_l",//LeftMiddleProximal
		"middle_02_l",//LeftMiddleIntermediate
		"middle_03_l",//LeftMiddleDistal
		"ring_01_l",//LeftRingProximal
		"ring_02_l",//LeftRingIntermediate
		"ring_03_l",//LeftRingDistal
		"pinky_01_l",//LeftLittleProximal
		"pinky_02_l",//LeftLittleIntermediate
		"pinky_03_l",//LeftLittleDistal
		
		"clavicle_r",//RightShoulder
		"upperarm_r",//RightUpperArm
		"lowerarm_r",//RightLowerArm
		"hand_r",//RightHand
		"thumb_01_r",//RightThumbProximal
		"thumb_02_r",//RightThumbIntermediate
		"thumb_03_r",//RightThumbDistal
		"index_01_r",//RightIndexProximal
		"index_02_r",//RightIndexIntermediate
		"index_03_r",//RightIndexDistal
		"middle_01_r",//RightMiddleProximal
		"middle_02_r",//RightMiddleIntermediate
		"middle_03_r",//RightMiddleDistal
		"ring_01_r",//RightRingProximal
		"ring_02_r",//RightRingIntermediate
		"ring_03_r",//RightRingDistal
		"pinky_01_r",//RightLittleProximal
		"pinky_02_r",//RightLittleIntermediate
		"pinky_03_r",//RightLittleDistal
	};

	

	const TArray<FString> FaceBones_3 = {
		"LeftEye",//"Hips/Spine/Spine1/Spine2/Neck/Head/LeftEye",//LeftEye
		"RightEye",//"Hips/Spine/Spine1/Spine2/Neck/Head/RightEye",//RightEye
		"Jaw_End",//"Hips/Spine/Spine1/Spine2/Neck/Head/Jaw/Jaw_End",//Jaw
	};

	//与下列官方顺序不同
	//C:\Program Files\Epic Games\UE_5.0\Engine\Source\Runtime\AugmentedReality\Public\ARTrackable.h
	const TArray<FString> BlendShapeNames_Dmman = {
		// Right eye blend shapes
		"blendShape.eyeBlinkRight",
		"blendShape.eyeLookDownRight",
		"blendShape.eyeLookInRight",
		"blendShape.eyeLookOutRight",
		"blendShape.eyeLookUpRight",
		"blendShape.eyeSquintRight",
		"blendShape.eyeWideRight",
		// Left eye blend shapes
		"blendShape.eyeBlinkLeft",
		"blendShape.eyeLookDownLeft",
		"blendShape.eyeLookInLeft",
		"blendShape.eyeLookOutLeft",
		"blendShape.eyeLookUpLeft",
		"blendShape.eyeSquintLeft",
		"blendShape.eyeWideLeft",
		// Jaw blend shapes
		"blendShape.jawForward",
		"blendShape.jawRight",
		"blendShape.jawLeft",
		"blendShape.jawOpen",
		// Mouth blend shapes
		"blendShape.mouthClose",
		"blendShape.mouthFunnel",
		"blendShape.mouthPucker",
		"blendShape.mouthRight",
		"blendShape.mouthLeft",
		"blendShape.mouthSmileLeft",
		"blendShape.mouthSmileRight",
		"blendShape.mouthFrownRight",
		"blendShape.mouthFrownLeft",
		"blendShape.mouthDimpleRight",
		"blendShape.mouthDimpleLeft",
		"blendShape.mouthStretchRight",
		"blendShape.mouthStretchLeft",
		"blendShape.mouthRollLower",
		"blendShape.mouthRollUpper",
		"blendShape.mouthShrugLower",
		"blendShape.mouthShrugUpper",
		"blendShape.mouthPressRight",
		"blendShape.mouthPressLeft",
		"blendShape.mouthLowerDownRight",
		"blendShape.mouthLowerDownLeft",
		"blendShape.mouthUpperUpRight",
		"blendShape.mouthUpperUpLeft",
		// Brow blend shapes
		"blendShape.browDownRight",
		"blendShape.browDownLeft",
		"blendShape.browInnerUp",
		"blendShape.browOuterUpRight",
		"blendShape.browOuterUpLeft",
		// Cheek blend shapes
		"blendShape.cheekPuff",
		"blendShape.cheekSquintRight",
		"blendShape.cheekSquintLeft",
		// Nose blend shapes
		"blendShape.noseSneerRight",
		"blendShape.noseSneerLeft"
	};

	//与上边BlendShapeNames_Dmman顺序保持一致
	//来自于
	//C:\Program Files\Epic Games\UE_5.0\Engine\Source\Runtime\AugmentedReality\Public\ARTrackable.h
	//enum EARFaceBlendShape
	const TArray<FString> BlendShapeNames_ARKIT = {
		// Right eye blend shapes
		"EyeBlinkRight",
		"EyeLookDownRight",
		"EyeLookInRight",
		"EyeLookOutRight",
		"EyeLookUpRight",
		"EyeSquintRight",
		"EyeWideRight",
		// Left eye blend shapes
		"EyeBlinkLeft",
		"EyeLookDownLeft",
		"EyeLookInLeft",
		"EyeLookOutLeft",
		"EyeLookUpLeft",
		"EyeSquintLeft",
		"EyeWideLeft",
		// Jaw blend shapes
		"JawForward",
		"JawLeft",
		"JawRight",
		"JawOpen",
		// Mouth blend shapes
		"MouthClose",
		"MouthFunnel",
		"MouthPucker",
		"MouthRight",
		"MouthLeft",
		"MouthSmileLeft",
		"MouthSmileRight",
		"MouthFrownRight",
		"MouthFrownLeft",
		"MouthDimpleRight",
		"MouthDimpleLeft",
		"MouthStretchRight",
		"MouthStretchLeft",
		"MouthRollLower",
		"MouthRollUpper",
		"MouthShrugLower",
		"MouthShrugUpper",
		"MouthPressRight",
		"MouthPressLeft",
		"MouthLowerDownRight",
		"MouthLowerDownLeft",
		"MouthUpperUpRight",
		"MouthUpperUpLeft",
		// Brow blend shapes
		"BrowDownRight",
		"BrowDownLeft",
		"BrowInnerUp",
		"BrowOuterUpRight",
		"BrowOuterUpLeft",
		// Cheek blend shapes
		"CheekPuff",
		"CheekSquintRight",
		"CheekSquintLeft",
		// Nose blend shapes
		"NoseSneerRight",
		"NoseSneerLeft",
		// TongueOut,
		// // Treat the head rotation as curves for LiveLink support
		// HeadYaw,
		// HeadPitch,
		// HeadRoll,
		// // Treat eye rotation as curves for LiveLink support
		// LeftEyeYaw,
		// LeftEyePitch,
		// LeftEyeRoll,
		// RightEyeYaw,
		// RightEyePitch,
		// RightEyeRoll,
		// MAX
	};
	
	// enum class EARFaceBlendShape : uint8
	// {
	// 	// Left eye blend shapes
	// 	EyeBlinkLeft,
	// 	EyeLookDownLeft,
	// 	EyeLookInLeft,
	// 	EyeLookOutLeft,
	// 	EyeLookUpLeft,
	// 	EyeSquintLeft,
	// 	EyeWideLeft,
	// 	// Right eye blend shapes
	// 	EyeBlinkRight,
	// 	EyeLookDownRight,
	// 	EyeLookInRight,
	// 	EyeLookOutRight,
	// 	EyeLookUpRight,
	// 	EyeSquintRight,
	// 	EyeWideRight,
	// 	// Jaw blend shapes
	// 	JawForward,
	// 	JawLeft,
	// 	JawRight,
	// 	JawOpen,
	// 	// Mouth blend shapes
	// 	MouthClose,
	// 	MouthFunnel,
	// 	MouthPucker,
	// 	MouthLeft,
	// 	MouthRight,
	// 	MouthSmileLeft,
	// 	MouthSmileRight,
	// 	MouthFrownLeft,
	// 	MouthFrownRight,
	// 	MouthDimpleLeft,
	// 	MouthDimpleRight,
	// 	MouthStretchLeft,
	// 	MouthStretchRight,
	// 	MouthRollLower,
	// 	MouthRollUpper,
	// 	MouthShrugLower,
	// 	MouthShrugUpper,
	// 	MouthPressLeft,
	// 	MouthPressRight,
	// 	MouthLowerDownLeft,
	// 	MouthLowerDownRight,
	// 	MouthUpperUpLeft,
	// 	MouthUpperUpRight,
	// 	// Brow blend shapes
	// 	BrowDownLeft,
	// 	BrowDownRight,
	// 	BrowInnerUp,
	// 	BrowOuterUpLeft,
	// 	BrowOuterUpRight,
	// 	// Cheek blend shapes
	// 	CheekPuff,
	// 	CheekSquintLeft,
	// 	CheekSquintRight,
	// 	// Nose blend shapes
	// 	NoseSneerLeft,
	// 	NoseSneerRight,
	// 	TongueOut,
	// 	// Treat the head rotation as curves for LiveLink support
	// 	HeadYaw,
	// 	HeadPitch,
	// 	HeadRoll,
	// 	// Treat eye rotation as curves for LiveLink support
	// 	LeftEyeYaw,
	// 	LeftEyePitch,
	// 	LeftEyeRoll,
	// 	RightEyeYaw,
	// 	RightEyePitch,
	// 	RightEyeRoll,
	// 	MAX
	// };
	
};