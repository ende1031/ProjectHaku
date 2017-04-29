#include "Monster.h"

Monster::Monster(Texture texture, MonsterData data)
{
	Start(texture, data);
	cout << data.pattern << "패턴 몬스터 생성" << endl;
}

Monster::~Monster()
{
}

void Monster::Start(Texture texture, MonsterData data)
{
	m_bActive = true;
	m_MonsterData = data;

	m_pSprite = Device::GetSprite();
	m_pTexture = texture.GetTexture();

	m_AniTimer = 0;
	m_AniNum = 0;
	m_ColTimer = 0;

	m_radius = m_MonsterData.radius;
	m_HP = m_MonsterData.maxHP;

	m_alpha = 0;
	m_color = D3DCOLOR_ARGB(m_alpha, 255, 255, 255);
	m_rect = { 0, 0, (LONG)m_MonsterData.rectRight, (LONG)m_MonsterData.rectBottom };
	m_width = (float)m_rect.right;
	m_height = (float)m_rect.bottom;

	//패턴별 시작 위치 등 설정
	switch (m_MonsterData.pattern)
	{
	case 0:
		m_vPos = D3DXVECTOR3(900 - m_width/2, 100 - m_height/2, 0);
		break;
	case 1:
		m_vPos = D3DXVECTOR3(900 - m_width / 2, 250 - m_height / 2, 0);
		break;
	case 2:
		m_vPos = D3DXVECTOR3(900 - m_width / 2, 400 - m_height / 2, 0);
		break;
	}
}

void Monster::Update(float deltaTime)
{
	m_ColTimer += deltaTime;
	FadeIn(&m_alpha, deltaTime);
	SpecialPattern(deltaTime);
	Animation(m_MonsterData.rowNum, m_MonsterData.lastNum, 0.1f, deltaTime);

	if (m_HP <= 0)
	{
		m_bActive = false;
	}

	//패턴별 움직임 설정
	switch (m_MonsterData.pattern)
	{
	case 0:
		Move(-300, 0, deltaTime);
		break;
	case 1:
		Move(-300, 0, deltaTime);
		break;
	case 2:
		Move(-300, 0, deltaTime);
		break;
	}

	if (m_vPos.x < 0 - m_width)
	{
		cout << "화면 밖으로 나간 몬스터 삭제" << endl;
		m_bActive = false;
	}
}

void Monster::SpecialPattern(float deltaTime)
{
	//상속받아서 사용하도록
	//딱히 안써도 상관은 없음.
}

void Monster::ColFire()
{
	if (m_ColTimer > 0.2f)
	{
		cout << "몬스터 타격" << endl;
		m_HP--;
		m_ColTimer = 0;
	}
}