object formEdit: TformEdit
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = #1048#1079#1084#1077#1085#1077#1085#1080#1077
  ClientHeight = 216
  ClientWidth = 298
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object btn_ok: TButton
    AlignWithMargins = True
    Left = 10
    Top = 183
    Width = 75
    Height = 28
    Margins.Left = 10
    Margins.Bottom = 5
    Align = alLeft
    Caption = #1054#1050
    TabOrder = 0
    OnClick = btn_okClick
    ExplicitLeft = 15
  end
  object btn_cancel: TButton
    AlignWithMargins = True
    Left = 213
    Top = 183
    Width = 75
    Height = 28
    Margins.Right = 10
    Margins.Bottom = 5
    Align = alRight
    Cancel = True
    Caption = #1054#1090#1084#1077#1085#1072
    Default = True
    ModalResult = 2
    TabOrder = 1
    OnClick = btn_cancelClick
  end
  object panel_grd: TGridPanel
    AlignWithMargins = True
    Left = 3
    Top = 3
    Width = 290
    Height = 174
    Margins.Right = 5
    Align = alTop
    BevelKind = bkFlat
    BevelOuter = bvNone
    ColumnCollection = <
      item
        Value = 69.423219608710940000
      end
      item
        Value = 30.576780391289070000
      end>
    ControlCollection = <
      item
        Column = 1
        Control = lbl_name
        Row = 1
      end
      item
        Column = 1
        Control = lbl_spicies
        Row = 2
      end
      item
        Column = 1
        Control = lbl_rare
        Row = 3
      end
      item
        Column = 0
        Control = txt_name
        Row = 1
      end
      item
        Column = 0
        Control = txt_spicies
        Row = 2
      end
      item
        Column = 0
        Control = txt_rare
        Row = 3
      end
      item
        Column = 0
        Control = lbl_idValue
        Row = 0
      end
      item
        Column = 1
        Control = lbl_id
        Row = 0
      end>
    RowCollection = <
      item
        Value = 25.000000000000000000
      end
      item
        Value = 25.000000000000000000
      end
      item
        Value = 25.000000000000000000
      end
      item
        Value = 25.000000000000000000
      end>
    TabOrder = 2
    object lbl_name: TLabel
      AlignWithMargins = True
      Left = 201
      Top = 45
      Width = 48
      Height = 36
      Align = alLeft
      Caption = #1053#1072#1079#1074#1072#1085#1080#1077
      ExplicitHeight = 13
    end
    object lbl_spicies: TLabel
      AlignWithMargins = True
      Left = 201
      Top = 87
      Width = 62
      Height = 36
      Align = alLeft
      Caption = #1042#1089#1077#1075#1086' '#1074#1080#1076#1086#1074
      ExplicitHeight = 13
    end
    object lbl_rare: TLabel
      AlignWithMargins = True
      Left = 201
      Top = 129
      Width = 71
      Height = 38
      Align = alLeft
      Caption = #1056#1077#1076#1082#1080#1093' '#1074#1080#1076#1086#1074
      ExplicitHeight = 13
    end
    object txt_name: TEdit
      AlignWithMargins = True
      Left = 3
      Top = 45
      Width = 185
      Height = 22
      Margins.Right = 10
      Margins.Bottom = 17
      Align = alClient
      TabOrder = 0
      ExplicitHeight = 21
    end
    object txt_spicies: TEdit
      AlignWithMargins = True
      Left = 3
      Top = 87
      Width = 185
      Height = 22
      Margins.Right = 10
      Margins.Bottom = 17
      Align = alClient
      NumbersOnly = True
      TabOrder = 1
      ExplicitHeight = 21
    end
    object txt_rare: TEdit
      AlignWithMargins = True
      Left = 3
      Top = 129
      Width = 185
      Height = 24
      Margins.Right = 10
      Margins.Bottom = 17
      Align = alClient
      NumbersOnly = True
      TabOrder = 2
      ExplicitHeight = 21
    end
    object lbl_idValue: TLabel
      AlignWithMargins = True
      Left = 176
      Top = 3
      Width = 12
      Height = 36
      Margins.Right = 10
      Align = alRight
      Caption = '-/-'
      ExplicitHeight = 13
    end
    object lbl_id: TLabel
      AlignWithMargins = True
      Left = 201
      Top = 3
      Width = 28
      Height = 36
      Align = alLeft
      Caption = #1050#1083#1102#1095
      ExplicitHeight = 13
    end
  end
end
