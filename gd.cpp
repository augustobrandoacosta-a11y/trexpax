#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include <Geode/ui/Popup.hpp>

using namespace geode::prelude;

// ============================================================================
// STEP 1: DEFINE THE CUSTOM TREXPAXDASH INTERFACE PANEL
// ============================================================================
class TrexpaxdashPopup : public geode::Popup<> {
protected:
    bool setup() override {
        auto winSize = CCDirector::sharedDirector()->getWinSize();

        // 1. Set the main header title on the pop-up panel
        this->setTitle("Trexpaxdash Maker >:3", "goldFont.fnt", 0.9f);

        // 2. Add the official "by trexpax hq" studio credit label
        auto brandLabel = CCLabelBMFont::create("by trexpax hq", "chatFont.fnt");
        brandLabel->setPosition({ winSize.width / 2, winSize.height / 2 + 50 });
        brandLabel->setScale(0.6f);
        brandLabel->setColor({ 0, 255, 150 }); // Trexpax Neon Dinosaur Green!
        m_mainLayer->addChild(brandLabel);

        // 3. Add an action description message for the user
        auto descLabel = CCLabelBMFont::create("Create and override game textures live!", "bigFont.fnt");
        descLabel->setPosition({ winSize.width / 2, winSize.height / 2 + 15 });
        descLabel->setScale(0.4f);
        m_mainLayer->addChild(descLabel);

        // 4. Create an interactive green "Build Pack" button assembly
        auto btnSprite = ButtonSprite::create("Build Pack", "goldFont.fnt", "GJ_button_01.png");
        auto buildBtn = CCMenuItemSpriteExtra::create(
            btnSprite,
            this,
            menu_selector(TrexpaxdashPopup::onBuildPack)
        );
        
        // 5. Position and mount the button inside the layout menu
        m_buttonMenu->addChild(buildBtn);
        buildBtn->setPosition({ 0, -50 }); // Centers below the text lines

        return true;
    }

    // This function executes when someone taps the "Build Pack" button
    void onBuildPack(CCObject* sender) {
        FLAlertLayer::create(
            "Trexpaxdash Engine",
            "Creating custom textures directory inside game/geode/config...",
            "Awesome!"
        )->show();
    }

public:
    // Factory method to initialize and render the anchored dialog box cleanly
    static TrexpaxdashPopup* create() {
        auto ret = new TrexpaxdashPopup();
        if (ret && ret->initAnchored(360, 220)) {
            ret->autorelease();
            return ret;
        }
        CC_SAFE_DELETE(ret);
        return nullptr;
    }
};

// ============================================================================
// STEP 2: HOOK INTO THE MAIN MENU TO INJECT THE TREXPAXDASH ENTRY POINT
// ============================================================================
class $modify(TrexpaxdashMenu, MenuLayer) {
    bool init() {
        if (!MenuLayer::init()) {
            return false;
        }

        auto menu = this->getChildByID("main-menu");
        if (menu) {
            auto trexSprite = CCSprite::createWithSpriteFrameName("GJ_downloadsBtn_001.png");
            trexSprite->setColor({0, 255, 150}); // Signature neon green look!

            auto trexButton = CCMenuItemSpriteExtra::create(
                trexSprite,
                this,
                menu_selector(TrexpaxdashMenu::onTrexpaxdashClick)
            );

            trexButton->setID("trexpaxdash-maker-btn");
            
            menu->addChild(trexButton);
            menu->updateLayout(); 
        }

        return true;
    }

    void onTrexpaxdashClick(CCObject* sender) {
        TrexpaxdashPopup::create()->show();
    }
};
