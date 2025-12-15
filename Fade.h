#pragma once
#include "KamataEngine.h"

using namespace KamataEngine;

class Fade {
public:
	enum class Status {
		None,
		FadeIn,
		FadeOut,
	};

	void Initialize();

	void Update();

	void Draw();

	// フェード開始
	void Start(Status status, float duration);

	// フェード停止
	void Stop();

	// フェード終了判定
	bool IsFinished() const;

private:
	Sprite* sprite_ = nullptr;

	// 現在のフェードの継続時間
	Status status_ = Status::None;

	// フェードの持続時間
	float duration_ = 0.0f;
	//  経過時間カウンター
	float counter_ = 0.0f;
};
