object mainForm: TmainForm
  Left = 0
  Top = 0
  Caption = #1057#1087#1080#1089#1086#1082' '#1079#1086#1086#1087#1072#1088#1082#1086#1074
  ClientHeight = 260
  ClientWidth = 476
  Color = clWindow
  Constraints.MinHeight = 319
  Constraints.MinWidth = 492
  DoubleBuffered = True
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  Menu = main_menu
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object data_grid: TStringGrid
    Left = 0
    Top = 25
    Width = 476
    Height = 216
    Align = alClient
    ColCount = 3
    DefaultColWidth = 110
    DoubleBuffered = True
    FixedColor = clGrayText
    FixedCols = 0
    RowCount = 1
    FixedRows = 0
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goColSizing, goRowSelect]
    ParentDoubleBuffered = False
    PopupMenu = popup_grid
    TabOrder = 0
    OnKeyUp = data_gridKeyUp
    ColWidths = (
      110
      110
      110)
  end
  object statusBar: TStatusBar
    Left = 0
    Top = 241
    Width = 476
    Height = 19
    Panels = <
      item
        Text = #1042#1089#1077#1075#1086' '#1079#1072#1087#1080#1089#1077#1081':'
        Width = 90
      end
      item
        Width = 50
      end>
  end
  object header_grid: TGridPanel
    AlignWithMargins = True
    Left = 3
    Top = 3
    Width = 470
    Height = 19
    Align = alTop
    BevelEdges = []
    BevelOuter = bvNone
    ColumnCollection = <
      item
        SizeStyle = ssAbsolute
        Value = 110.000000000000000000
      end
      item
        SizeStyle = ssAbsolute
        Value = 110.000000000000000000
      end
      item
        SizeStyle = ssAbsolute
        Value = 110.000000000000000000
      end
      item
        Value = 100.000000000000000000
      end>
    ControlCollection = <
      item
        Column = 0
        Control = lbl_headerName
        Row = 0
      end
      item
        Column = 1
        Control = lbl_headerSpicies
        Row = 0
      end
      item
        Column = 2
        Control = lbl_headerRare
        Row = 0
      end
      item
        Column = 3
        Control = lbl_headerKey
        Row = 0
      end>
    ParentBackground = False
    ParentColor = True
    RowCollection = <
      item
        Value = 100.000000000000000000
      end>
    ShowCaption = False
    TabOrder = 2
    object lbl_headerName: TLabel
      Left = 0
      Top = 0
      Width = 48
      Height = 19
      Align = alLeft
      Caption = #1053#1072#1079#1074#1072#1085#1080#1077
      Layout = tlBottom
      ExplicitHeight = 13
    end
    object lbl_headerSpicies: TLabel
      Left = 110
      Top = 0
      Width = 62
      Height = 19
      Align = alLeft
      Caption = #1042#1089#1077#1075#1086' '#1074#1080#1076#1086#1074
      Layout = tlBottom
      ExplicitHeight = 13
    end
    object lbl_headerRare: TLabel
      Left = 220
      Top = 0
      Width = 71
      Height = 19
      Align = alLeft
      Caption = #1056#1077#1076#1082#1080#1093' '#1074#1080#1076#1086#1074
      Layout = tlBottom
      ExplicitHeight = 13
    end
    object lbl_headerKey: TLabel
      Left = 330
      Top = 0
      Width = 3
      Height = 19
      Align = alLeft
      Layout = tlBottom
      ExplicitHeight = 13
    end
  end
  object popup_grid: TPopupMenu
    Left = 368
    Top = 120
    object popup_edit: TMenuItem
      Caption = #1048#1079#1084#1077#1085#1080#1090#1100
      OnClick = popup_editClick
    end
    object popup_remove: TMenuItem
      Caption = #1059#1076#1072#1083#1080#1090#1100
      OnClick = popup_removeClick
    end
  end
  object main_menu: TMainMenu
    Left = 328
    Top = 120
    object menu_file: TMenuItem
      Caption = #1060#1072#1081#1083
      object menu_clear: TMenuItem
        Caption = #1054#1095#1080#1089#1090#1080#1090#1100
        OnClick = menu_clearClick
      end
      object menu_save: TMenuItem
        Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100
        OnClick = menu_saveClick
      end
      object menu_load: TMenuItem
        Caption = #1047#1072#1075#1088#1091#1079#1080#1090#1100
        OnClick = menu_loadClick
      end
      object menu_exit: TMenuItem
        Caption = #1042#1099#1093#1086#1076
        OnClick = menu_exitClick
      end
    end
    object menu_edit: TMenuItem
      Caption = #1055#1088#1072#1074#1082#1072
      object menu_add: TMenuItem
        Caption = #1044#1086#1073#1072#1074#1080#1090#1100' '#1101#1083#1077#1084#1077#1085#1090
        OnClick = menu_editClick
      end
      object menu_editElem: TMenuItem
        Tag = 1
        Caption = #1048#1079#1084#1077#1085#1080#1090#1100' '#1101#1083#1077#1084#1077#1085#1090
        GroupIndex = 1
        OnClick = menu_editClick
      end
      object menu_remove: TMenuItem
        Tag = 2
        Caption = #1059#1076#1072#1083#1080#1090#1100' '#1101#1083#1077#1084#1077#1085#1090
        GroupIndex = 2
        OnClick = menu_editClick
      end
      object menu_showKeys: TMenuItem
        Caption = #1055#1086#1082#1072#1079#1072#1090#1100' '#1082#1083#1102#1095#1080
        GroupIndex = 2
        OnClick = menu_showKeysClick
      end
    end
    object menu_run: TMenuItem
      Caption = #1047#1072#1087#1091#1089#1082
      object menu_runA: TMenuItem
        Caption = #1047#1072#1087#1091#1089#1090#1080#1090#1100' '#1040
        OnClick = menu_runAClick
      end
      object menu_runB: TMenuItem
        Tag = 1
        Caption = #1047#1072#1087#1091#1089#1090#1080#1090#1100' '#1041
        OnClick = menu_runBClick
      end
    end
    object menu_search: TMenuItem
      Caption = #1055#1086#1080#1089#1082
      OnClick = menu_searchClick
    end
    object menu_about: TMenuItem
      Caption = #1054' '#1087#1088#1086#1075#1088#1072#1084#1084#1077
      OnClick = menu_aboutClick
    end
  end
end
