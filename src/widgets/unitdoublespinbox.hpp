/****************************************************************************

 Copyright (c) 2013, Hans Robeers
 All rights reserved.

 BSD 2-Clause License

 Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

   * Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.

   * Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.

 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

****************************************************************************/

#ifndef QTUNITS_UNITDOUBLESPINBOX_H
#define QTUNITS_UNITDOUBLESPINBOX_H

#include "widgets/unitwidget.hpp"

#include <QDoubleSpinBox>

namespace qt { namespace units {
    inline
    int sc_exp(qreal r, int e=0) {
      if (r<10)
        return e;
      return sc_exp(r/10, ++e);
    }

    template<class UnitType>
    class UnitDoubleSpinbox : public UnitWidget<UnitType>
    {
    private:
        QDoubleSpinBox *_spinBox;

    public:
        explicit UnitDoubleSpinbox(QWidget *parent = 0) :
            UnitWidget<UnitType>(parent)
        {
            _spinBox = new QDoubleSpinBox();

            UnitWidgetBase::connectValueChanged(_spinBox);
        }

        virtual void setReadOnly(bool readOnly)
        {
            _spinBox->setReadOnly(readOnly);
        }

        QDoubleSpinBox* getSpinBox() {
            return _spinBox;
        }

    protected:
        virtual QWidget *valueWidget()
        {
            return _spinBox;
        }

        virtual void onValueChange(UnitType &newValue)
        {
            _spinBox->setValue(newValue.value());
            // _spinBox->setDecimals(std::max(0, 4-sc_exp(newValue.value())));
        }
    };

}} // namespace qt::units

#endif // QTUNITS_UNITDOUBLESPINBOX_H
