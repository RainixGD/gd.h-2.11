#ifndef DELEGATES_H
#define DELEGATES_H

#include <gd.h>

namespace gd {
    class GJGameLevel;
    class NumberInputLayer;
    class SetIDPopup;
    class CCTextInputNode;
    class GJDropDownLayer;
    class SongInfoObject;
    class GJSpecialColorSelect;
    class CCCircleWave;
    class CurrencyRewardLayer;
    class DialogLayer;
    class CCScrollLayerExt;
    class GJUserScore;

    enum GJSongError {
        kGJSongErrorUnknown = 0,
    };

    class TextInputDelegate {
        virtual void textChanged(CCTextInputNode*) {}
        virtual void textInputOpened(CCTextInputNode*) {}
        virtual void textInputClosed(CCTextInputNode*) {}
        virtual void textInputShouldOffset(CCTextInputNode*, float) {}
        virtual void textInputReturn(CCTextInputNode*) {}
        virtual bool allowTextInput(CCTextInputNode*) { return true; }
    };

    class GameRateDelegate {
    public:
        virtual void updateRate(void) {}
    };

    class DialogDelegate {
    public:
        virtual void dialogClosed(DialogLayer*);
    };

    class GooglePlayDelegate {
        virtual void googlePlaySignedIn() {}
    };

    class ColorSelectDelegate {
        virtual void colorSelectClosed(cocos2d::CCNode*);
    };

    class ColorSetupDelegate {
    public:
        virtual void colorSetupClosed(int) {}
    };

    class ColorPickerDelegate {
        virtual void colorValueChanged(cocos2d::ccColor3B color);
    };

    class GJSpecialColorSelectDelegate {
        virtual void colorSelectClosed(GJSpecialColorSelect*, int);
    };

    class GJRotationControlDelegate {
        virtual void angleChangeBegin(void);
        virtual void angleChangeEnded(void);
        virtual void angleChanged(float);
    };

    class GJScaleControlDelegate {
        virtual void scaleChangeBegin(void);
        virtual void scaleChangeEnded(void);
        virtual void scaleChanged(float);
    };

    class MusicDownloadDelegate {
        virtual void downloadSongFailed(int, GJSongError);
        virtual void downloadSongFinished(SongInfoObject*);
        virtual void loadSongInfoFailed(int, GJSongError);
        virtual void loadSongInfoFinished(SongInfoObject*);
        virtual void songStateChanged(void);
    };

    enum UpdateResponse {
        kUpdateResponseUnknown,
        kUpdateResponseUpToDate,
        kUpdateResponseGameVerOutOfDate,
        kUpdateResponseUpdateSuccess,
    };

    enum CommentError {
        kCommentErrorUnknown_not_REd = 0x0,
    };

    enum LikeItemType {
        kLikeItemTypeUnknown,
    };

    class LeaderboardManagerDelegate {
        virtual void updateUserScoreFinished(void) {}
        virtual void updateUserScoreFailed(void) {}
        virtual void loadLeaderboardFinished(cocos2d::CCArray*, char const*) {}
        virtual void loadLeaderboardFailed(char const*) {}
    };

    class UserInfoDelegate {
        virtual void getUserInfoFailed(int) {}
        virtual void getUserInfoFinished(GJUserScore*) {}
        virtual void userInfoChanged(GJUserScore*) {}
    };

    class CommentUploadDelegate {
        virtual void commentUploadFinished(int) {}
        virtual void commentUploadFailed(int, CommentError) {}
        virtual void commentDeleteFailed(int, int) {}
    };

    class LevelCommentDelegate {
        virtual void loadCommentsFinished(cocos2d::CCArray*, const char*) {}
        virtual void loadCommentsFailed(const char*) {}
        virtual void updateUserScoreFinished(void) {}
        virtual void setupPageInfo(std::string, const char*) {}
    };

    class LevelDownloadDelegate {
    public:
        virtual void levelDownloadFinished(GJGameLevel*);
        virtual void levelDownloadFailed(int);
    };

    class LevelDeleteDelegate {
        virtual void levelDeleteFinished(int);
        virtual void levelDeleteFailed(int);
    };

    class LevelUpdateDelegate {
    public:
        virtual void levelUpdateFinished(GJGameLevel*, UpdateResponse);
        virtual void levelUpdateFailed(int);
    };

    class UploadActionDelegate {
        virtual void uploadActionFinished(int, int) {};
        virtual void uploadActionFailed(int, int) {};
    };

    class UploadPopupDelegate {
        virtual void onClosePopup(void) {};
    };
    
    class LikeItemDelegate {
        virtual void likedItem(LikeItemType, int, bool);
    };

    class RateLevelDelegate {
        virtual void rateLevelClosed(void);
    };

    class NumberInputDelegate {
        virtual void numberInputClosed(NumberInputLayer*);
    };

    class SetIDPopupDelegate {
        virtual void setIDPopupClosed(SetIDPopup*, int);
    };

    class GJDropDownLayerDelegate {
    public:
        virtual void dropDownLayerWillClose(GJDropDownLayer*);
    };

    class CCCircleWaveDelegate {
        virtual void circleWaveWillBeRemoved(CCCircleWave*) {}
    };

    enum AccountError {
        kAccountErrorUnknown = 0,
    };

    enum BackupAccountError {
        kBackupAccountErrorUnknown = 0,
    };

    struct GJAccountRegisterDelegate {
        virtual void registerAccountFailed(AccountError error) {}
        virtual void registerAccountFinished(void) {}
    };

    struct GJAccountLoginDelegate {
        virtual void loginAccountFailed(AccountError error) {}
        virtual void loginAccountFinished(int, int) {}
    };

    struct GJAccountDelegate {
        virtual void accountStatusChanged(void) {}
    };

    struct GJAccountBackupDelegate {
        virtual void backupAccountFailed(BackupAccountError) {}
        virtual void backupAccountFinished(void) {}
    };

    struct GJAccountSyncDelegate {
        virtual void syncAccountFailed(BackupAccountError) {}
        virtual void syncAccountFinished(void) {}
    };

    struct GJAccountSettingsDelegate {
        virtual void updateSettingsFailed(void) {}
        virtual void updateSettingsFinished(void) {}
    };

    struct DynamicScrollDelegate {
        void updatePageWithObject(cocos2d::CCObject*, cocos2d::CCObject*) {}
    };

    class CurrencyRewardDelegate {
        virtual void currencyWillExit(CurrencyRewardLayer*);
    };

}

#endif
