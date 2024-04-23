// SPDX-FileCopyrightText: (C) 2023 - 2024 Matthias Fehring <https://www.huessenbergnetz.de>
//
// SPDX-License-Identifier: BSD-3-Clause

import de.huessenbergnetz.cutelystforms 1.0

Form {
    htmlId: "littleForm"
    htmlClass: "form"
    name: "littleForm"
    label: cTr("%n dwarf(s)", "", dwarfsCount)

    buttons: [
        FormButton {

        },
        FormButton {

        }
    ]

    fieldsets: [
        Fieldset {
            htmlId: "fieldset1"
            htmlClass: test
            legend: FormLegend {
                text: "A greate legend"
            }

            Select {
                htmlId: "selectField"

                Option {
                    label: "optionLabel"
                }
            }

            Select {
                optgroups: [
                    Optgroup {
                        label: "Group A"
                        Option {
                            text: "Opt 1"
                            value: "1"
                        }
                        Option {
                            text: "Opt 2"
                            value: "2"
                        }
                    },
                    Optgroup {
                        label: "Group B"
                        Option {
                            text: "Opt 3"
                            value: "3"
                        }
                        Option {
                            text: "Opt 4"
                            value: "4"
                        }
                    }
                ]
            }
        },
        Fieldset {
            htmlId: "fieldset2"
            legend: FormLegend {
                text: cTranslate("MyForm", "Another great legend")
            }

            HiddenForm {
                name: "csrfprotectiontoken"
                value: cCsrfToken()
            }
        }
    ]
}
