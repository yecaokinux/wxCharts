/*
	Copyright (c) 2016 Xavier Leclercq

	Permission is hereby granted, free of charge, to any person obtaining a
	copy of this software and associated documentation files (the "Software"),
	to deal in the Software without restriction, including without limitation
	the rights to use, copy, modify, merge, publish, distribute, sublicense,
	and/or sell copies of the Software, and to permit persons to whom the
	Software is furnished to do so, subject to the following conditions:

	The above copyright notice and this permission notice shall be included in
	all copies or substantial portions of the Software.

	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
	THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
	FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
	IN THE SOFTWARE.
*/

#include "wxlinechartoptions.h"

wxLineChartOptions::wxLineChartOptions()
	: m_dotRadius(4), m_dotStrokeWidth(1),
	m_lineWidth(2), m_hitDetectionRange(24)
{
}

const wxChartGridOptions& wxLineChartOptions::GetGridOptions() const
{
	return m_gridOptions;
}

wxChartGridOptions& wxLineChartOptions::GetGridOptions()
{
	return m_gridOptions;
}

wxDouble wxLineChartOptions::GetDotRadius() const
{
	return m_dotRadius;
}

unsigned int wxLineChartOptions::GetDotStrokeWidth() const
{
	return m_dotStrokeWidth;
}

unsigned int wxLineChartOptions::GetLineWidth() const
{
	return m_lineWidth;
}

wxDouble wxLineChartOptions::GetHitDetectionRange() const
{
	return m_hitDetectionRange;
}
