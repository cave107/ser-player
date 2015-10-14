// ---------------------------------------------------------------------
// Copyright (C) 2015 Chris Garry
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>
// ---------------------------------------------------------------------


#ifndef FRAME_SLIDER_H
#define FRAME_SLIDER_H

#include <QSlider>


class c_frame_slider : public QSlider
{
    Q_OBJECT

public:
    c_frame_slider(QWidget *parent = 0);
    int get_start_frame();
    int get_end_frame();
    void set_start_marker(int frame);
    void set_end_marker(int frame);
    void delete_all_markers();


private slots:
    void ShowContextMenu(const QPoint& pos);

protected:
    void paintEvent(QPaintEvent *event);

private:
    int positionForValue(int val) const;

    int m_start_marker;
    int m_end_marker;

};

#endif // FRAME_SLIDER_H
