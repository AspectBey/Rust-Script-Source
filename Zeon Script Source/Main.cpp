#include "Main.h"
#include <Windows.h>
#include <string>
#include <cstdlib>
#include <stdlib.h>
#include <ostream>
#include <random>
#include <tchar.h>
#include <regex>
#include <sstream>
#include <winbase.h>
#include <time.h>
#include <stdio.h>
#include <WinInet.h>
#include <filesystem>
#include <fstream>
#include <string.h>
#include <cstring>
#include <ctime>
#include "Vanity/Features.h"
#include "Vanity/RecoilTables.h"
#include ".\xorstr.hpp"
#include "guard.h"
#include "keybinds.h"

#define _WIN32_WINNT 0x0400

static bool keyb, random_active, show_random, randomonline, randomxy_active, show_xycontrol, controlxy_active, show_another_window, reconline, hip_active, ak_active, lr_active, mp5_active, thompson_active, custom_active, semi_active, m249_active, python_active, m39_active, bMuzzleBoost, holo_active, sniper_active, simple_active, x16_active, silencer_active, boost_active, bRapidf = false;
static bool g_open = true;

static int ak, lr, mp5, custom, thompson, semi, m249, python, xscope, xxscope, smscope, hlscope, silencer, mboost = 1;
static int nonests = 3;
static int nonet = 2;
static int nonetts = 2;
static int XSCALE = 1;
static int YSCALE = 1;
static int width = 300;
static int height = 400;

static float rpdelay = 50;
static float game_sensitivity = 1;
static float XCONTROL = 1;
static float YCONTROL = 1;

using namespace std;
vector<string> serial;

void loadserial()
{
	serial.push_back("2492918555"); //owner
	serial.push_back("479754335"); //levi
	serial.push_back("1821064857"); //pozx
}
namespace CurrentWeapon {
	double BarrelAttachment() {

		if (silencer_active == true) {
			if (m249_active == true)
				Multiplyer::Barrel.Suppressor = 0.75;
			if (custom_active == true)
				Multiplyer::Barrel.Suppressor = 0.85;
			if (simple_active == true || holo_active == true)
				return 0.8;
			if (sniper_active == true && silencer_active == true)
				return 1.0;
			else
				return Multiplyer::Barrel.Suppressor;
		}
		else if (bMuzzleBoost == true) {
			return Multiplyer::Barrel.None;
		}
		else
			return Multiplyer::Barrel.None;
	}
	double ScopeAttachment() {
		if (sniper_active == true) {
			if (custom_active == true || thompson_active == true) {
				if (sniper_active == true)
					return Multiplyer::Scope.x8 + 0.75;
			}
			return Multiplyer::Scope.x8;
		}
		if (x16_active == true) {
			if (custom_active == true || thompson_active == true) {
				if (x16_active == true)
					return Multiplyer::Scope.x16 + 0.75;
			}
			return Multiplyer::Scope.x16;
		}
		else if (simple_active == true) {
			if (custom_active == true || thompson_active == true) {
				if (simple_active == true)
					return Multiplyer::Scope.Simple + 0.1;
			}
			return Multiplyer::Scope.Simple;
		}

		else if (holo_active == true) {
			if (custom_active == true || thompson_active == true) {
				if (holo_active == true)
					return Multiplyer::Scope.Holo + 0.3;
			}
			return Multiplyer::Scope.Holo;
		}
		else
			return Multiplyer::Scope.None;
	}

	double x(int b) {

		if (randomxy_active == false) {

			if (ak_active) {
				return (Recoil_Ak47[b].x * ScopeAttachment() * BarrelAttachment() / 4) / game_sensitivity / XCONTROL;
			}
			else if (lr_active) {
				return (Recoil_Lr300[b].x * ScopeAttachment() * BarrelAttachment() / 4) / game_sensitivity / XCONTROL;
			}
			else if (mp5_active) {
				return (Recoil_Mp5a4[b].x * ScopeAttachment() * BarrelAttachment() / 4) / game_sensitivity / XCONTROL;
			}
			else if (thompson_active) {
				return (Recoil_Thompson_g[b].x * ScopeAttachment() * BarrelAttachment() / 4) / game_sensitivity / XCONTROL;
			}
			else if (custom_active) {
				return (Recoil_Custom_g[b].x * ScopeAttachment() * BarrelAttachment() / 4) / game_sensitivity / XCONTROL;
			}
			else if (m249_active) {
				return (Recoil_M249[b].x * ScopeAttachment() * BarrelAttachment() / 4) / game_sensitivity / XCONTROL;
			}
			else if (semi_active) {
				return (Recoil_Semi_r[b].x * ScopeAttachment() * BarrelAttachment() / 4) / game_sensitivity / XCONTROL;
			}
			else if (python_active) {
				return (python_t[b].x * ScopeAttachment() * BarrelAttachment() / 4) / game_sensitivity / XCONTROL;
			}
			else if (m39_active) {
				return (m39_t[b].x * ScopeAttachment() * BarrelAttachment() / 4) / game_sensitivity / XCONTROL;
			}
			else
				return 0;
		}
		if (randomxy_active == true) {                                                                 //X RANDOMIZATION ON AND OFF
			if (ak_active) {
				return ((Recoil_Ak47[b].x * ScopeAttachment()) * BarrelAttachment()) / 4 / game_sensitivity / XCONTROL + rand() % (XSCALE + XSCALE) + (-XSCALE);
			}
			else if (lr_active) {
				return ((Recoil_Lr300[b].x * ScopeAttachment()) * BarrelAttachment()) / 4 / game_sensitivity / XCONTROL + rand() % (XSCALE + XSCALE) + (-XSCALE);
			}
			else if (mp5_active) {
				return ((Recoil_Mp5a4[b].x * ScopeAttachment()) * BarrelAttachment()) / 4 / game_sensitivity / XCONTROL + rand() % (XSCALE + XSCALE) + (-XSCALE);
			}
			else if (thompson_active) {
				return ((Recoil_Thompson_g[b].x * ScopeAttachment()) * BarrelAttachment()) / 4 / game_sensitivity / XCONTROL + rand() % (XSCALE + XSCALE) + (-XSCALE);
			}
			else if (custom_active) {
				return ((Recoil_Custom_g[b].x * ScopeAttachment()) * BarrelAttachment()) / 4 / game_sensitivity / XCONTROL + rand() % (XSCALE + XSCALE) + (-XSCALE);
			}
			else if (m249_active) {
				return ((Recoil_M249[b].x * ScopeAttachment()) * BarrelAttachment()) / 4 / game_sensitivity / XCONTROL + rand() % (XSCALE + XSCALE) + (-XSCALE);
			}
			else if (semi_active) {
				return ((Recoil_Semi_r[b].x * ScopeAttachment()) * BarrelAttachment()) / 4 / game_sensitivity / XCONTROL + rand() % (XSCALE + XSCALE) + (-XSCALE);
			}
			else if (python_active) {
				return ((python_t[b].x * ScopeAttachment()) * BarrelAttachment()) / 4 / game_sensitivity / XCONTROL + rand() % (XSCALE + XSCALE) + (-XSCALE);
			}
			else if (m39_active) {
				return ((m39_t[b].x * ScopeAttachment()) * BarrelAttachment()) / 4 / game_sensitivity / XCONTROL + rand() % (XSCALE + XSCALE) + (-XSCALE);
			}
			else
				return 0;
		}
	}
	double y(int b) {                                                                                       //Y RANDOMIZATION ON AND OFF
		if (randomxy_active == false) {
			if (ak_active) {
				return (Recoil_Ak47[b].y * ScopeAttachment() * BarrelAttachment() / 4) / game_sensitivity / YCONTROL;
			}
			else if (lr_active) {
				return (Recoil_Lr300[b].y * ScopeAttachment() * BarrelAttachment() / 4) / game_sensitivity / YCONTROL;
			}
			else if (mp5_active) {
				return (Recoil_Mp5a4[b].y * ScopeAttachment() * BarrelAttachment() / 4) / game_sensitivity / YCONTROL;
			}
			else if (thompson_active) {
				return (Recoil_Thompson_g[b].y * ScopeAttachment() * BarrelAttachment() / 4) / game_sensitivity / YCONTROL;
			}
			else if (custom_active) {
				return (Recoil_Custom_g[b].y * ScopeAttachment() * BarrelAttachment() / 4) / game_sensitivity / YCONTROL;
			}
			else if (m249_active) {
				return (Recoil_M249[b].y * ScopeAttachment() * BarrelAttachment() / 4) / game_sensitivity / YCONTROL;
			}
			else if (semi_active) {
				return (Recoil_Semi_r[b].y * ScopeAttachment() * BarrelAttachment() / 4) / game_sensitivity / YCONTROL;
			}
			else if (python_active) {
				return (python_t[b].y * ScopeAttachment() * BarrelAttachment() / 4) / game_sensitivity / YCONTROL;
			}
			else if (m39_active) {
				return (m39_t[b].y * ScopeAttachment() * BarrelAttachment() / 4) / game_sensitivity / YCONTROL;
			}
			else
				return 0;
		}
		if (randomxy_active == true) {


			if (ak_active) {
				return ((Recoil_Ak47[b].y * ScopeAttachment()) * BarrelAttachment()) / 4 / game_sensitivity / YCONTROL + rand() % (YSCALE + YSCALE) + (-YSCALE);
			}
			else if (lr_active) {
				return ((Recoil_Lr300[b].y * ScopeAttachment()) * BarrelAttachment()) / 4 / game_sensitivity / YCONTROL + rand() % (YSCALE + YSCALE) + (-YSCALE);;
			}
			else if (mp5_active) {
				return ((Recoil_Mp5a4[b].y * ScopeAttachment()) * BarrelAttachment()) / 4 / game_sensitivity / YCONTROL + rand() % (YSCALE + YSCALE) + (-YSCALE);;
			}
			else if (thompson_active) {
				return ((Recoil_Thompson_g[b].y * ScopeAttachment()) * BarrelAttachment()) / 4 / game_sensitivity / YCONTROL + rand() % (YSCALE + YSCALE) + (-YSCALE);;
			}
			else if (custom_active) {
				return ((Recoil_Custom_g[b].y * ScopeAttachment()) * BarrelAttachment()) / 4 / game_sensitivity / YCONTROL + rand() % (YSCALE + YSCALE) + (-YSCALE);;
			}
			else if (m249_active) {
				return ((Recoil_M249[b].y * ScopeAttachment()) * BarrelAttachment()) / 4 / game_sensitivity / YCONTROL + rand() % (YSCALE + YSCALE) + (-YSCALE);;
			}
			else if (semi_active) {
				return ((Recoil_Semi_r[b].y * ScopeAttachment()) * BarrelAttachment()) / 4 / game_sensitivity / YCONTROL + rand() % (YSCALE + YSCALE) + (-YSCALE);;
			}
			else if (python_active) {
				return ((python_t[b].y * ScopeAttachment()) * BarrelAttachment()) / 4 / game_sensitivity / YCONTROL + rand() % (YSCALE + YSCALE) + (-YSCALE);;
			}
			else if (m39_active) {
				return ((m39_t[b].y * ScopeAttachment()) * BarrelAttachment()) / 4 / game_sensitivity / YCONTROL + rand() % (YSCALE + YSCALE) + (-YSCALE);;
			}
			else
				return 0;
		}

	}
	double Delay() {
		if (ak_active == true)
			return WeaponData::AK47.Delay;
		else if (lr_active == true)
			return WeaponData::LR300.Delay;
		else if (mp5_active == true)
			return WeaponData::MP5.Delay;
		else if (thompson_active == true)
			return WeaponData::THOMPSON.Delay;
		else if (custom_active == true)
			return WeaponData::CUSTOM_SMG.Delay;
		else if (m249_active == true)
			return WeaponData::M249.Delay;
		else if (semi_active == true)
			return WeaponData::SEMI.Delay;
		else if (python_active == true) {
			return WeaponData::PYTHON.Delay;
		}
		else if (m39_active == true) {
			return WeaponData::M39.Delay;
		}

		return 0;
	}
	double Control(int bullet) {
		if (ak_active == true)
			return ControlTime_Ak47[bullet];
		else if (lr_active == true)
			return control_lr[bullet];
		else if (mp5_active == true)
			return control_mp5[bullet];
		else if (thompson_active == true)
			return control_thompson[bullet];
		else if (custom_active == true)
			return control_custom[bullet];
		else if (m249_active == true)
			return WeaponData::M249.Delay;
		else if (semi_active == true)
			return WeaponData::SEMI.Delay;
		else if (python_active == true) {
			return WeaponData::PYTHON.Delay;
		}
		else if (m39_active == true) {
			return WeaponData::M39.Delay;
		}
		return 0;
	}
	int Bullet() {
		if (ak_active == true)
			return Recoil_Ak47.size() - 1;
		else if (lr_active == true)
			return Recoil_Lr300.size() - 1;
		else if (mp5_active == true)
			return Recoil_Mp5a4.size() - 1;
		else if (thompson_active == true)
			return Recoil_Thompson_g.size() - 1;
		else if (custom_active == true)
			return Recoil_Custom_g.size() - 1;
		else if (m249_active == true)
			return Recoil_M249.size() - 1;
		else if (semi_active == true)
			return Recoil_Semi_r.size() - 1;
		else if (python_active == true)
			return python_t.size() - 1;
		else if (m39_active == true)
			return m39_t.size() - 1;
		else
			return 0;
	}
	bool WeaponActive() {
		if (ak_active == true || lr_active == true || mp5_active == true || thompson_active == true || custom_active == true || semi_active == true || m249_active == true || python_active == true || m39_active == true)
			return true;
		else
			return false;
	}

	void RecoilBreak(int count) {
		if (semi_active == true) {
			mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
		}
		if (python_active == true) {
			mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
		}
		if (m39_active == true) {
			mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
		}
		if (semi_active == true) {
			mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
		}
		else if (m249_active == true) {
		}
		else if (semi_active != true || m249_active != true || m39_active != true || python_active != true) {
			if (count == CurrentWeapon::Bullet()) {
				mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
			}
		}
	}
};
namespace settings {
	void Smoothing(double delay, double control_time, int x, int y) {

		int x_ = 0, y_ = 0, t_ = 0;
		for (int i = 1; i <= (int)control_time; ++i) {
			int xI = i * x / (int)control_time;
			int yI = i * y / (int)control_time;
			int tI = i * (int)control_time / (int)control_time;
			mouse_event(1, (int)xI - (int)x_, (int)yI - (int)y_, 0, 0);
			pQuerySleep((int)tI - (int)t_);
			x_ = xI; y_ = yI; t_ = tI;
		}
		pQuerySleep((int)delay - (int)control_time);
	}
	int IsMuzzleBoost(float Delay) {
		if (bMuzzleBoost == true) {
			float difference = Delay * 0.1f;
			Delay = Delay - difference;
			return (int)Delay + 2;
		}
		else
			return (int)Delay;
	}
	bool RecoilExecution() {

		for (;;) {
			if (CurrentWeapon::WeaponActive() == true)
			{
				if (hip_active == false)
				{
					for (int i = 0; i <= CurrentWeapon::Bullet() && GetAsyncKeyState(VK_LBUTTON) & 0x8000 && GetAsyncKeyState(VK_RBUTTON) & 0x8000; i++)
					{
						Smoothing((int)IsMuzzleBoost((float)CurrentWeapon::Delay()), (int)IsMuzzleBoost(CurrentWeapon::Control(i)), (int)CurrentWeapon::x(i), (int)CurrentWeapon::y(i));
						CurrentWeapon::RecoilBreak(i);
					}
					Sleep(1);
				}
			}
			Sleep(1);
		}

		return false;
	}
	bool Recoils() {
		if (GetAsyncKeyState(akbind)) {

			ak_active = !ak_active;
			if (ak_active == true)
			{

				lr_active = false, mp5_active = false, thompson_active = false, custom_active = false, m249_active = false, semi_active = false; python_active = false; m39_active = false;
				Active_Weapon = "AK47";

				Sleep(200); Beep(150, 150); ak = 2;
			}
			else if (ak_active == false) {
				ak_active = false, lr_active = false, mp5_active = false, thompson_active = false, custom_active = false, m249_active = false, semi_active = false;
				holo_active = false, sniper_active = false, simple_active = false; x16_active = false;
				silencer_active = false;

				Active_Weapon = "NONE";
				Sleep(200); Beep(150, 150); ak = 1; nonet = 2;
			}
		}
		if (GetAsyncKeyState(lrbind)) {

			lr_active = !lr_active;
			if (lr_active == true)
			{
				ak_active = false, mp5_active = false, thompson_active = false, custom_active = false, m249_active = false, semi_active = false; python_active = false; m39_active = false;
				Active_Weapon = "LR300";
				Sleep(200); Beep(150, 150); lr = 2;
			}
			else if (lr_active == false) {
				ak_active = false, lr_active = false, mp5_active = false, thompson_active = false, custom_active = false, m249_active = false, semi_active = false;
				holo_active = false, sniper_active = false, simple_active = false; x16_active = false;
				silencer_active = false;

				Active_Weapon = "NONE";
				Sleep(200); Beep(150, 150); lr = 1; nonet = 2;
			}
		}
		if (GetAsyncKeyState(mpbind)) {

			mp5_active = !mp5_active;
			if (mp5_active == true)
			{
				ak_active = false, lr_active = false, thompson_active = false, custom_active = false, m249_active = false, semi_active = false; python_active = false; m39_active = false;
				Active_Weapon = "MP5";
				Sleep(200); Beep(150, 150); mp5 = 2;
			}
			else if (mp5_active == false) {
				ak_active = false, lr_active = false, mp5_active = false, thompson_active = false, custom_active = false, m249_active = false, semi_active = false;
				holo_active = false, sniper_active = false, simple_active = false; x16_active = false;
				silencer_active = false;

				Active_Weapon = "NONE";

				Sleep(200); Beep(150, 150); mp5 = 1; nonet = 2;
			}
		}
		if (GetAsyncKeyState(csbind) != 0) {

			custom_active = !custom_active;
			if (custom_active == true)
			{
				ak_active = false, lr_active = false, mp5_active = false, thompson_active = false, m249_active = false, semi_active = false; python_active = false; m39_active = false;

				Active_Weapon = "SMG";
				Sleep(200); Beep(150, 150); custom = 2;
			}
			else if (custom_active == false) {
				ak_active = false, lr_active = false, mp5_active = false, thompson_active = false, custom_active = false, m249_active = false, semi_active = false;
				holo_active = false, sniper_active = false, simple_active = false; x16_active = false;
				silencer_active = false;

				Active_Weapon = "NONE";
				Sleep(200); Beep(150, 150); custom = 1; nonet = 2;
			}
		}
		if (GetAsyncKeyState(tmbind) != 0) {

			thompson_active = !thompson_active;
			if (thompson_active == true)
			{
				ak_active = false, lr_active = false, mp5_active = false, custom_active = false, m249_active = false, semi_active = false; python_active = false; m39_active = false;

				Active_Weapon = "TOMMY";
				Sleep(200); Beep(150, 150); thompson = 2;
			}
			else if (thompson_active == false) {
				ak_active = false, lr_active = false, mp5_active = false, thompson_active = false, custom_active = false, m249_active = false, semi_active = false;
				holo_active = false, sniper_active = false, simple_active = false; x16_active = false;
				silencer_active = false;


				Active_Weapon = "NONE";
				Sleep(200); Beep(150, 150); thompson = 1; nonet = 2;
			}
		}
		if (GetAsyncKeyState(smbind) != 0) {

			semi_active = !semi_active;
			if (semi_active == true)
			{
				ak_active = false, lr_active = false, mp5_active = false, thompson_active = false, m249_active = false, custom_active = false; python_active = false; m39_active = false;

				Active_Weapon = "SEMI";
				Sleep(200); Beep(150, 150); nonet = 2; semi = 2;
			}
			else if (semi_active == false) {
				ak_active = false, lr_active = false, mp5_active = false, thompson_active = false, custom_active = false, m249_active = false, semi_active = false;
				holo_active = false, sniper_active = false, simple_active = false; x16_active = false;
				silencer_active = false;

				Active_Weapon = "NONE";
				Sleep(200); Beep(150, 150); semi = 1; nonet = 2;
			}
		}
		if (GetAsyncKeyState(m2bind)) {

			m249_active = !m249_active;
			if (m249_active == true)
			{
				ak_active = false, lr_active = false, mp5_active = false, thompson_active = false, semi_active = false, custom_active = false; python_active = false; m39_active = false;

				Active_Weapon = "M249";
				Sleep(200); Beep(150, 150); nonet = 2; m249 = 2;
			}
			else if (m249_active == false) {
				ak_active = false, lr_active = false, mp5_active = false, thompson_active = false, custom_active = false, m249_active = false, semi_active = false;
				holo_active = false, sniper_active = false, simple_active = false; x16_active = false;
				silencer_active = false;

				Active_Weapon = "NONE";

				Sleep(200); Beep(150, 150); m249 = 1; nonet = 2;
			}
		}
		if (GetAsyncKeyState(ptbind) != 0) {

			python_active = !python_active;
			if (python_active == true)
			{
				ak_active = false, lr_active = false, mp5_active = false, thompson_active = false, semi_active = false, custom_active = false; m249_active = false; m39_active = false;

				Active_Weapon = "PYTHON";
				Sleep(200); Beep(150, 150); nonet = 2; python = 2;
			}
			else if (python_active == false) {
				ak_active = false, lr_active = false, mp5_active = false, thompson_active = false, custom_active = false, m249_active = false, semi_active = false;
				holo_active = false, sniper_active = false, simple_active = false; x16_active = false;
				silencer_active = false;

				Active_Weapon = "NONE";
				Sleep(200); Beep(150, 150); python = 1; nonet = 2;
			}
		}
		///////Scopes
		if (GetAsyncKeyState(hhbind)) {
			holo_active = !holo_active;
			if (holo_active == true)
			{
				sniper_active = false, simple_active = false; x16_active = false;
				
				Active_Scopes = "HOLO";

				Sleep(150); Beep(150, 150);
			}
			else if (holo_active == false) {
				
				Active_Scopes = "NONE";

				Sleep(150); Beep(150, 150); 
			}
		}
		if (GetAsyncKeyState(xxbind)) {
			sniper_active = !sniper_active;
			if (sniper_active == true)
			{
				holo_active = false, simple_active = false; x16_active = false;
				
				Active_Scopes = "8X";
				Sleep(150); Beep(150, 150); xscope = 2;
			}
			else if (holo_active == false) {
				
				Active_Scopes = "NONE";
				Sleep(150); Beep(150, 150); xscope = 1;
			}
		}
		if (GetAsyncKeyState(ssbind)) {
			simple_active = !simple_active;
			if (simple_active == true)
			{
				holo_active = false, sniper_active = false; x16_active = false;
				
				Active_Scopes = "SIMPLE";
				Sleep(150); Beep(150, 150); smscope = 2;
			}
			else if (simple_active == false) {
				
				Active_Scopes = "NONE";
				Sleep(150); Beep(150, 150); smscope = 1;
			}
		}
		if (GetAsyncKeyState(yybind) != 0) {
			x16_active = !x16_active;
			if (x16_active == true)
			{
				holo_active = false, sniper_active = false; simple_active = false;
				
				Active_Scopes = "16X";
				Sleep(150); Beep(150, 150); xxscope = 2;
			}
			else if (x16_active == false) {
				
				Active_Scopes = "NONE";
				Sleep(150); Beep(150, 150); xxscope = 1;
			}
		}
		if (GetAsyncKeyState(slbind) != 0) {
			silencer_active = !silencer_active;
			if (silencer_active == true)
			{
				Active_Barrel = "SILENCER";
				Sleep(150); Beep(150, 150); silencer = 2;
			}
			else if (silencer_active == false) {
				
				Active_Barrel = "NONE";
				Sleep(150); Beep(150, 150); silencer = 1;
			}


		}
		keybindi();
		if (GetAsyncKeyState(rpbind) & 0x8000)
		{
			if (bRapidf == true) {

				mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
				Sleep(rpdelay);
				mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
				Sleep(rpdelay);

			}
			else {

			}

		}
		return false;
	}
}

static std::string random_string(int length)
{
	std::string str("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ");
	std::random_device rd;
	std::mt19937 generator(rd());
	std::shuffle(str.begin(), str.end(), generator);
	return str.substr(0, length);    // assumes 32 < number of characters in str         
}
static DWORDLONG random_number(DWORDLONG min, DWORDLONG max)
{
	srand(time(0));
	DWORDLONG out = min + rand() % (max - min + 1);
	return out;
}
static std::string randomclassname = random_string(random_number(4, 16));

// Main code
int APIENTRY WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	SetPriorityClass(GetCurrentProcess(), REALTIME_PRIORITY_CLASS);
	CreateThread(0, 0, (LPTHREAD_START_ROUTINE)settings::RecoilExecution, 0, 0, 0);

	WNDCLASSEX wc = { sizeof(WNDCLASSEX), CS_CLASSDC, WndProc, 0L, 0L, GetModuleHandle(NULL), NULL, NULL, NULL, NULL, randomclassname.c_str(), NULL };
	RegisterClassEx(&wc);
	main_hwnd = CreateWindow(wc.lpszClassName, randomclassname.c_str(), WS_POPUP, 0, 0, 5, 5, NULL, NULL, wc.hInstance, NULL);

	if (!CreateDeviceD3D(main_hwnd)) {
		CleanupDeviceD3D();
		UnregisterClass(wc.lpszClassName, wc.hInstance);
		return 1;
	}
	ShowWindow(main_hwnd, SW_HIDE);
	UpdateWindow(main_hwnd);
	ImGui::CreateContext();

	ImGuiIO& io = ImGui::GetIO();
	io.IniFilename = nullptr; //crutial for not leaving the imgui.ini file
	io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable; // Enable Multi-Viewport / Platform Windows
	ImGuiStyle* style = &ImGui::GetStyle();

	style->WindowPadding = ImVec2(15, 15);
	style->FramePadding = ImVec2(2, 2);
	style->ItemInnerSpacing = ImVec2(8, 6);
	style->IndentSpacing = 25.0f;
	style->ScrollbarSize = 15.0f;
	style->ScrollbarRounding = 9.0f;
	style->GrabMinSize = 5.0f;
	style->GrabRounding = 3.0f;

	style->Colors[ImGuiCol_Text] = ImVec4(0.95f, 0.96f, 0.98f, 1.00f);
	style->Colors[ImGuiCol_TextDisabled] = ImVec4(0.24f, 0.23f, 0.29f, 1.00f);
	style->Colors[ImGuiCol_WindowBg] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
	style->Colors[ImGuiCol_PopupBg] = ImVec4(0.07f, 0.07f, 0.09f, 1.00f);
	style->Colors[ImGuiCol_Border] = ImVec4(1.0f, 0.0f, 0.0f, 0.01f);
	style->Colors[ImGuiCol_BorderShadow] = ImVec4(0.92f, 0.91f, 0.88f, 0.00f);
	style->Colors[ImGuiCol_FrameBg] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
	style->Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.24f, 0.23f, 0.29f, 1.00f);
	style->Colors[ImGuiCol_FrameBgActive] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
	style->Colors[ImGuiCol_TitleBg] = ImVec4(1.0f, 0.09f, 0.12f, 0.70f);
	style->Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(1.00f, 0.98f, 0.95f, 0.75f);
	style->Colors[ImGuiCol_TitleBgActive] = ImVec4(0.07f, 0.07f, 0.09f, 1.00f);
	style->Colors[ImGuiCol_MenuBarBg] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
	style->Colors[ImGuiCol_ScrollbarBg] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
	style->Colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.80f, 0.80f, 0.83f, 0.31f);
	style->Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
	style->Colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
	style->Colors[ImGuiCol_CheckMark] = ImVec4(0.0f, 0.6f, 1.0f, 1.0f);
	style->Colors[ImGuiCol_SliderGrab] = ImVec4(0.80f, 0.80f, 0.83f, 0.31f);
	style->Colors[ImGuiCol_SliderGrabActive] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
	style->Colors[ImGuiCol_Button] = ImVec4(0.2f, 0.4f, 0.9f, 1.00f);
	style->Colors[ImGuiCol_ButtonHovered] = ImVec4(0.24f, 0.23f, 0.29f, 1.00f);
	style->Colors[ImGuiCol_ButtonActive] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
	style->Colors[ImGuiCol_Header] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
	style->Colors[ImGuiCol_HeaderHovered] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
	style->Colors[ImGuiCol_HeaderActive] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
	style->Colors[ImGuiCol_ResizeGrip] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	style->Colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
	style->Colors[ImGuiCol_ResizeGripActive] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
	style->Colors[ImGuiCol_PlotLines] = ImVec4(0.40f, 0.39f, 0.38f, 0.63f);
	style->Colors[ImGuiCol_PlotLinesHovered] = ImVec4(0.25f, 1.00f, 0.00f, 1.00f);
	style->Colors[ImGuiCol_PlotHistogram] = ImVec4(0.40f, 0.39f, 0.38f, 0.63f);
	style->Colors[ImGuiCol_PlotHistogramHovered] = ImVec4(0.25f, 1.00f, 0.00f, 1.00f);
	style->Colors[ImGuiCol_TextSelectedBg] = ImVec4(0.25f, 1.00f, 0.00f, 0.43f);
	style->Colors[ImGuiCol_ModalWindowDarkening] = ImVec4(1.00f, 0.98f, 0.95f, 0.73f);
	style->Colors[ImGuiCol_Separator] = ImVec4(0.2f, 0.4f, 0.9f, 1.00f);

	ImGui_ImplWin32_Init(main_hwnd);
	ImGui_ImplDX9_Init(g_pd3dDevice);
	DWORD window_flags = ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar;

	RECT screen_rect;
	GetWindowRect(GetDesktopWindow(), &screen_rect);
	auto x = float(screen_rect.right - width) / 2.f;
	auto y = float(screen_rect.bottom - height) / 2.f;

	MSG msg;
	ZeroMemory(&msg, sizeof(msg));
	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
			continue;


		}
		ImGui_ImplDX9_NewFrame();
		ImGui_ImplWin32_NewFrame();
		ImGui::NewFrame();
		{
			ImGui::SetNextWindowPos(ImVec2(x, y), ImGuiCond_Once);
			ImGui::SetNextWindowSize(ImVec2(width, height));
			ImGui::SetNextWindowBgAlpha(1.0f);
			ImGui::Begin(randomclassname.c_str(), &loader_active);
			{
				Crack_Önleyici();

				static int currentColumn = 0;
				char license[255] = "You License Code";
				static bool animate = true;
				static float progress = 0.0f, progress_dir = 1.0f;
				switch (currentColumn) {
					break;
				case 0:
					::SetWindowPos(main_hwnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_DRAWFRAME | SWP_NOMOVE | SWP_NOSIZE | SWP_SHOWWINDOW);
					ImGui::Text("");
					ImGui::TextColored(ImVec4(0.2f, 0.4f, 0.9f, 1.00f), "             Sensitivity!");
					ImGui::Text("");
					ImGui::Text("");
					ImGui::SameLine(50);
					ImGui::SliderFloat("                  ", &game_sensitivity, 0, 2, "% .2f");
					ImGui::Text("");
					ImGui::Text("_________________________________________________________________________");
					ImGui::Text("");
					ImGui::Text("");
					ImGui::Text("");
					ImGui::SameLine(100);
					if (ImGui::Button("START SCRIPT")) currentColumn = 1;
					break;
				case 1:
					settings::Recoils();
					HW_PROFILE_INFO hwProfileInfo;
					if (GetCurrentHwProfile(&hwProfileInfo) != NULL) {
					}
					ImGui::Text("");
					ImGui::Separator();
					ImGui::Text("");
					if (ImGui::CollapsingHeader("NO-Recoil Script")) {
						ImGui::Text("[NUM0]	AK-47         [F2] 8X	");
						ImGui::Text("[NUM1]	lr-300        [F3] 16X");
						ImGui::Text("[NUM2]	Mp54a         [F4] holo");
						ImGui::Text("[NUM3]	Custom        [F5] SIMPLE");
						ImGui::Text("[NUM4]	THOMPSO       [F6] sILENCER");
						ImGui::Text("[NUM5]	SAR           [DEL] RESET");
						ImGui::Text("[NUM6]	M249                     ");
						ImGui::Text("[NUM8]	PYTHON                   ");
						ImGui::Text("[NUM9]	M39                      ");


					}
					if (ImGui::CollapsingHeader("Helpers")) {
						ImGui::Checkbox("Enable Recoil Randomize", &randomonline);
						ImGui::Checkbox("Enable Rapid Fire", &bRapidf);
					}
					if (ImGui::CollapsingHeader("Keybinds:")) {
						keyb = true;
						ImGui::Text("");

						if (reconline || randomonline == false) {
							width = 300;
							height = 450;
						}
						else {
							width = 300;
							height = 600;
						}
							
						keybindi();
						ImGui::Combo("AK47", &selectedItem, item, IM_ARRAYSIZE(item));
						ImGui::Combo("LR300", &selectedItemL, itemL, IM_ARRAYSIZE(itemL));
						ImGui::Combo("MP5A4", &selectedItemM, itemM, IM_ARRAYSIZE(itemM));
						ImGui::Combo("CUSTOM", &selectedItemC, itemM, IM_ARRAYSIZE(itemM));
						ImGui::Combo("THOMPSON", &selectedItemT, itemT, IM_ARRAYSIZE(itemT));
						ImGui::Combo("SAR-RIFLE", &selectedItemS, itemS, IM_ARRAYSIZE(itemS));
						ImGui::Combo("M249", &selectedItemM2, itemM2, IM_ARRAYSIZE(itemM2));
						ImGui::Combo("Python", &selectedItemPT, itemPT, IM_ARRAYSIZE(itemPT));
						ImGui::Text("");
						ImGui::Combo("8X", &selectedItem8x, item8x, IM_ARRAYSIZE(item8x));
						ImGui::Combo("16X", &selectedItem16x, item16x, IM_ARRAYSIZE(item16x));
						ImGui::Combo("Holo", &selectedItemHL, itemHL, IM_ARRAYSIZE(itemHL));
						ImGui::Combo("Simple", &selectedItemSS, itemSS, IM_ARRAYSIZE(itemSS));
						ImGui::Combo("Silencer", &selectedItemSL, itemSL, IM_ARRAYSIZE(itemSL));
						ImGui::Text("");
						if (ImGui::Button("Reset all keys")) {
							resetkeys();
						};
					}
					else {
						keyb = false;
						width = 300;
						height = 400;
					}
					break;
				}
			}
			ImGui::End();
		}
		ImGui::EndFrame();
		g_pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, 0, 1.0f, 0);
		if (g_pd3dDevice->BeginScene() >= 0)
		{
			ImGui::Render();
			ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
			g_pd3dDevice->EndScene();
		}
		if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
		{
			ImGui::UpdatePlatformWindows();
			ImGui::RenderPlatformWindowsDefault();
		}

		HRESULT result = g_pd3dDevice->Present(NULL, NULL, NULL, NULL);

		if (result == D3DERR_DEVICELOST && g_pd3dDevice->TestCooperativeLevel() == D3DERR_DEVICENOTRESET) {
			ResetDevice();
		}
		if (!loader_active) {
			msg.message = WM_QUIT;
		}
	}

	ImGui_ImplDX9_Shutdown();
	ImGui_ImplWin32_Shutdown();
	ImGui::DestroyContext();

	CleanupDeviceD3D();
	DestroyWindow(main_hwnd);
	UnregisterClass(wc.lpszClassName, wc.hInstance);

	return 0;

}

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {

	if (ImGui_ImplWin32_WndProcHandler(hWnd, msg, wParam, lParam))
		return true;

	switch (msg)
	{
	case WM_SIZE:
		if (g_pd3dDevice != NULL && wParam != SIZE_MINIMIZED)
		{
			g_d3dpp.BackBufferWidth = LOWORD(lParam);
			g_d3dpp.BackBufferHeight = HIWORD(lParam);
			ResetDevice();
		}
		return 0;
	case WM_SYSCOMMAND:
		if ((wParam & 0xfff0) == SC_KEYMENU)
			return 0;
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hWnd, msg, wParam, lParam);
}
void pQuerySleep(int ms)
{
	LONGLONG timerResolution;
	LONGLONG wantedTime;
	LONGLONG currentTime;
	QueryPerformanceFrequency((LARGE_INTEGER*)&timerResolution);
	timerResolution /= 1000;
	QueryPerformanceCounter((LARGE_INTEGER*)&currentTime);
	wantedTime = currentTime / timerResolution + ms;
	currentTime = 0;
	while (currentTime < wantedTime)
	{
		QueryPerformanceCounter((LARGE_INTEGER*)&currentTime);
		currentTime /= timerResolution;
	}
}