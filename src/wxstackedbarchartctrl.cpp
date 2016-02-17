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

#include "wxstackedbarchartctrl.h"
#include <wx/dcbuffer.h>
#include <wx/graphics.h>

wxStackedBarChartCtrl::wxStackedBarChartCtrl(wxWindow *parent,
											 wxWindowID id,
											 const wxBarChartData &data,
											 const wxPoint &pos,
											 const wxSize &size,
											 long style)
	: wxChartCtrl(parent, id, pos, size, style),
	m_grid(
		wxPoint2DDouble(m_options.GetPadding().GetLeft(), m_options.GetPadding().GetRight()),
		size, data.GetLabels(), GetCumulativeMinValue(data.GetDatasets()),
		GetCumulativeMaxValue(data.GetDatasets()), m_options.GetGridOptions()
		)
{
}

const wxStackedBarChartOptions& wxStackedBarChartCtrl::GetOptions() const
{
	return m_options;
}

wxDouble wxStackedBarChartCtrl::GetCumulativeMinValue(const wxVector<wxBarChartDataset::ptr>& datasets)
{
	wxDouble result = 0;

	size_t i = 0;
	while (true)
	{
		wxDouble sum = 0;
		bool stop = true;
		for (size_t j = 0; j < datasets.size(); ++j)
		{
			const wxBarChartDataset& dataset = *datasets[j];
			if (i < dataset.GetData().size())
			{
				sum += dataset.GetData()[i];
				stop = false;
			}
		}
		if (sum < result)
		{
			result = sum;
		}
		if (stop)
		{
			break;
		}
		++i;
	}

	return result;
}

wxDouble wxStackedBarChartCtrl::GetCumulativeMaxValue(const wxVector<wxBarChartDataset::ptr>& datasets)
{
	wxDouble result = 0;

	size_t i = 0;
	while (true)
	{
		wxDouble sum = 0;
		bool stop = true;
		for (size_t j = 0; j < datasets.size(); ++j)
		{
			const wxBarChartDataset& dataset = *datasets[j];
			if (i < dataset.GetData().size())
			{
				sum += dataset.GetData()[i];
				stop = false;
			}
		}
		if (sum > result)
		{
			result = sum;
		}
		if (stop)
		{
			break;
		}
		++i;
	}

	return result;
}

void wxStackedBarChartCtrl::Resize(const wxSize &size)
{
	m_grid.Resize(size);
}

wxSharedPtr<wxVector<const wxChartElement*> > wxStackedBarChartCtrl::GetActiveElements(const wxPoint &point)
{
	wxSharedPtr<wxVector<const wxChartElement*> > activeElements(new wxVector<const wxChartElement*>());
	return activeElements;
}

void wxStackedBarChartCtrl::OnPaint(wxPaintEvent &evt)
{
	wxAutoBufferedPaintDC dc(this);

	dc.Clear();

	wxGraphicsContext* gc = wxGraphicsContext::Create(dc);
	if (gc)
	{
		m_grid.Draw(*gc);

		delete gc;
	}
}

BEGIN_EVENT_TABLE(wxStackedBarChartCtrl, wxChartCtrl)
	EVT_PAINT(wxStackedBarChartCtrl::OnPaint)
END_EVENT_TABLE()
