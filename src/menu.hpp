#include "includes.hpp"

namespace Menu
{
	bool open = true;
	bool value = false;

	void Draw()
	{
		ImGui::Begin("Menu");

		ImGui::SetWindowSize(ImVec2{ 700, 400 });
		ImGui::Checkbox("Value", &value);

		ImGui::End();
	}
}