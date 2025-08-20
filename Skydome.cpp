#include "skydome.h"

void skydome::Initialize(Model* model, Camera* camera) {
	assert(model);

	model_ = model;
	camera_ = camera;
	worldTransform_.Initialize();
}

void skydome::Update() {
	// 行列を定数バッファに転送
	worldTransform_.TransferMatrix();
}

void skydome::Draw() {
	// モデル描画
	model_->Draw(worldTransform_, *camera_);
}