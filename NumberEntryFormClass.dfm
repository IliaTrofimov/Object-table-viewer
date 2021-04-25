object formNumEntry: TformNumEntry
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = #1042#1074#1077#1076#1080#1090#1077' '#1076#1086#1083#1102
  ClientHeight = 85
  ClientWidth = 213
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poOwnerFormCenter
  PixelsPerInch = 96
  TextHeight = 13
  object txt_number: TEdit
    Left = 8
    Top = 8
    Width = 197
    Height = 21
    MaxLength = 10
    TabOrder = 0
  end
  object btn_ok: TButton
    Left = 8
    Top = 52
    Width = 75
    Height = 25
    Caption = #1054#1050
    TabOrder = 1
    OnClick = btn_okClick
  end
end
