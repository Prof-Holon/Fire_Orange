Route13_MapScripts::
	.byte 0

Route13_EventScript_TrainerTips1::
	msgbox Route13_Text_LookToLeftOfThatPost, MSGBOX_SIGN
	end

Route13_EventScript_TrainerTips2::
	msgbox Route13_Text_SelectToSwitchItems, MSGBOX_SIGN
	end

Route13_EventScript_RouteSign::
	msgbox Route13_Text_RouteSign, MSGBOX_SIGN
	end

Route13_EventScript_MoveReminder::
	goto_if_questlog EventScript_ReleaseEnd
	special QuestLog_CutRecording
	lock
	faceplayer
	msgbox Route13_Text_TeachMonMoveForHeartScale
	checkitemspace ITEM_HEART_SCALE, 1
	compare VAR_RESULT, 0
	goto_if_ge 1, Route13_EventScript_AskTutorMon
	msgbox Route13_Text_NeedHeartScale
	releaseall
	end

Route13_EventScript_AskTutorMon::
	msgbox Route13_Text_WantMeToTeachMove, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route13_EventScript_EndTutorMove
	goto Route13_EventScript_ChooseMonToTutor
	end

Route13_EventScript_ChooseMonToTutor::
	msgbox Route13_Text_TutorWhichMon
	special ChooseMonForMoveRelearner
	waitstate
	goto_if_ge VAR_0x8004, PARTY_SIZE, Route13_EventScript_EndTutorMove
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, Route13_EventScript_CantTutorEgg
	goto_if_eq VAR_0x8005, 0, Route13_EventScript_NoMoveToTutorMon
	goto Route13_EventScript_ChooseMoveToTeach
	end

Route13_EventScript_ChooseMoveToTeach::
	msgbox Route13_Text_TeachWhichMove
	special TeachMoveRelearnerMove
	waitstate
	goto_if_eq VAR_0x8004, 0, Route13_EventScript_ChooseMonToTutor
	removeitem ITEM_HEART_SCALE, 1
	textcolor NPC_TEXT_COLOR_NEUTRAL
	msgbox Route13_Text_HandedOverHeartScale
	call EventScript_RestorePrevTextColor
	goto Route13_EventScript_EndTutorMove
	end

Route13_EventScript_NoMoveToTutorMon::
	msgbox Route13_Text_NoMoveICanTeachThatMon
	goto Route13_EventScript_ChooseMonToTutor
	end

Route13_EventScript_CantTutorEgg::
	msgbox Route13_Text_CantTeachAnEgg
	goto Route13_EventScript_ChooseMonToTutor
	end

Route13_EventScript_EndTutorMove::
	msgbox Route13_Text_NeedHeartScale
	release
	end
