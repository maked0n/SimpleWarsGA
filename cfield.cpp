#include "cfield.h"
using namespace Representation;

CShotRepresentation::CShotRepresentation(int xupperleft, int yupperleft) {
	m_rect.x = xupperleft;
	m_rect.y = yupperleft;
	m_rect.w = CELL_SIZE;
	m_rect.h = CELL_SIZE;
	m_type = Unit::EUnitClass::NO_UNIT;
}

SDL_Rect* CShotRepresentation::get_rect() {
	return &m_rect;
}

Unit::EUnitClass CShotRepresentation::type() const {
	return Unit::EUnitClass::NO_UNIT;
}

CUnitRepresentation::CUnitRepresentation(int xupperleft, int yupperleft, Unit::EUnitClass type) {
	m_rect.x = xupperleft;
	m_rect.y = yupperleft;
	m_rect.w = CELL_SIZE;
	m_rect.h = CELL_SIZE;
	m_type = type;
}

SDL_Rect* CUnitRepresentation::get_rect() {
	return &m_rect;
}

Unit::EUnitClass CUnitRepresentation::type() const {
	return m_type;
}

CField::CField(/*size_t vsize, size_t hsize*/) {
	/*m_field.resize(hsize);
	for(size_t i = 0; i < hsize; ++i) {
		m_field.resize(vsize);
		for(size_t j = 0; j < vsize; ++j) 
			m_field[i][j] = Unit::EUnitClass::NO_UNIT;
	}
	*/
	m_next_element = m_elements.begin();
}

bool CField::get_next(element& next) {
	if(m_next_element != m_elements.end()) {
		next = m_next_element++;
		return true;
	}
	else return false;
}

void CField::renew() {
	m_next_element = m_elements.begin();
}

void CField::add_element(IRepresentation* representation) {
	m_elements.push_back(representation);
}
